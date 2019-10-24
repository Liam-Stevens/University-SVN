#include <string>
#include <vector>
#include "iobuffer.h"
#include "symbols.h"
#include "abstract-syntax-tree.h"
#include <sstream>

// to shorten our code:
using namespace std ;
using namespace CS_IO_Buffers ;
using namespace CS_Symbol_Tables ;
using namespace Jack_Compiler ;

// ***** WHAT TO DO *****
//
// MODIFY the skeleton code below to parse a Jack class and construct the equivalent abstract syntax tree, ast.
//        The main function will print the ast formatted as XML
//
// NOTE: the correct segment and offset is recorded with every variable in the ast
//       so the code generator does not need to use any symbol tables
//
// NOTE: use the fatal function below to print fatal error messages with the current
//       input file position marked.
//
// The skeleton code has one function per non-terminal in the Jack grammar
//  - comments describing how to create relevant ast nodes prefix most functions
//  - ast nodes are immutable - you must create all the sub-trees before creating a new node
//
// The structure of the skeleton code is just a suggestion
//  - it matches the grammar but does not quite match the ast structure
//  - you will need to change the parameters / results / functions to suit your own logic
//  - you can change it as much as you like
//
// NOTE: the best place to start is to write code to parse the input without attempting to create
//       any ast nodes. If correct this parser will report errors when it finds syntax errors but
//       correct programs will fail because the tree printer will not be provided with a valid ast.
//       Once the parsing works modify your code to create the ast nodes.
//
// NOTE: the return -1 ; statements are only present so that this skeleton code will compile.
//       these statements need to be replaced by code that creates ast nodes.
//

// fatal error handling
static void fatal(string message)
{
    fatal_error(0,"***** Error:\n" + token_context() + message) ;
}

// The Jack grammar to be recognised:
// program          ::= One or more classes, each class in a separate file named <class_name>'.Jack'
// class            ::= 'class' identifier '{' class_var_decs subr_decs '}'
// class_var_decs   ::= (static_var_dec | field_var_dec)*
// static_var_dec   ::= 'static' type identifier (',' identifier)* ';'
// field_var_dec    ::= 'field' type identifier (',' identifier)* ';'
// type             ::= 'int' | 'char' | 'boolean' | identifier
// vtype            ::= 'void' | type
// subr_decs        ::= (constructor | function | method)*
// constructor      ::= 'constructor' identifier identifier '(' param_list ')' subr_body
// function         ::= 'function' vtype identifier '(' param_list ')' subr_body
// method           ::= 'method' vtype identifier '(' param_list ')' subr_body
// param_list       ::= ((type identifier) (',' type identifier)*)?
// subr_body        ::= '{' var_decs statements '}'
// var_decs         ::= var_dec*
// var_dec          ::= 'var' type identifier (',' identifier)* ';'

// statements       ::= statement*
// statement        ::= let | if | while | do | return
// let              ::= 'let' identifier index? '=' expr ';'
// if               ::= 'if' '(' expr ')' '{' statements '}' ('else' '{' statements '}')?
// while            ::= 'while' '(' expr ')' '{' statements '}'
// do               ::= 'do' identifier (id_call | call) ';'
// return           ::= 'return' expr? ';'

// expr             ::= term (infix_op term)*
// term             ::= integer_constant | string_constant | 'true' | 'false' | 'null' | 'this' | '(' expr ')' | unary_op term | var_term
// var_term         ::= identifier (index | id_call | call)?
// index            ::= '[' expr ']'
// id_call          ::= '.' identifier call
// call             ::= '(' expr_list ')'
// expr_list        ::= (expr (',' expr)*)?
// infix_op         ::= '+' | '-' | '*' | '/' | '&' | '|' | '<' | '>' | '='
// unary_op         ::= '-' | '~'


// forward declarations of one function per non-terminal rule in the Jack grammar - except for program
// NOTE: parse_type(), parse_vtype(), parse_unary_op() all return a Token not an ast
// NOTE: parse_static_var_dec(), parse_field_var_dec(), parse_var_dec() all return vector<ast> not an ast
//
ast parse_class() ;
ast parse_class_var_decs() ;
vector<ast> parse_static_var_dec() ;
vector<ast> parse_field_var_dec() ;
Token parse_type() ;
Token parse_vtype() ;
ast parse_subr_decs() ;
ast parse_constructor() ;
ast parse_function() ;
ast parse_method() ;
ast parse_param_list() ;
ast parse_subr_body() ;
ast parse_var_decs() ;
vector<ast> parse_var_dec() ;

ast parse_statements() ;
ast parse_statement() ;
ast parse_let() ;
ast parse_if() ;
ast parse_while() ;
ast parse_do() ;
ast parse_return() ;

ast parse_expr() ;
ast parse_term() ;
ast parse_var_term() ;
ast parse_index() ;
ast parse_id_call() ;
ast parse_call() ;
ast parse_expr_list() ;
ast parse_infix_op() ;
Token parse_unary_op() ;

//Symbol Table
symbols class_symbol_table;
int class_offset;
symbols function_symbol_table;
int function_offset;

int declare_variable(string name, string type, string segment)
{
    symbols symbol_table;
    int offset;

    if (segment == "static" || segment == "field")
    {
        symbol_table = class_symbol_table;
        offset = class_offset;
        class_offset++;
    }
    else
    {
        symbol_table = function_symbol_table;
        offset = function_offset;
        function_offset++;
    }

    st_variable new_var(name, type, segment, offset);
    insert_variables(symbol_table, name, new_var);

    return offset;
}

// class ::= 'class' identifier '{' class_var_decs subr_decs '}'
// create_class(myclassname,class_var_decs,class_subrs)
ast parse_class()
{
    push_error_context("parse_class()") ;

    class_symbol_table = create_variables();
    class_offset = 0;

    mustbe(tk_class);
    string className = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lcb);

    ast class_var = parse_class_var_decs();
    ast subr_decs = parse_subr_decs();

    mustbe(tk_rcb);

    delete_variables(class_symbol_table);

    pop_error_context() ;
    return create_class(className,class_var,subr_decs) ;
}

// class_var_decs ::= (static_var_dec | field_var_dec)*
// returns ast_class_var_decs: create_class_var_decs(vector<ast> decs)
// create_class_var_decs must be passed a vector of ast_var_dec
//
ast parse_class_var_decs()
{
    push_error_context("parse_class_var_decs()") ;

    vector<ast> class_declarations;

    while( have( current_token(), tk_class_var ) )
    {
        vector<ast> new_decs;
        if ( have( current_token(), tk_static ) )
        {
            new_decs = parse_static_var_dec();
        }

        else if ( have( current_token(), tk_field ) )
        {
            new_decs = parse_field_var_dec();
        }

        class_declarations.insert( class_declarations.end(), new_decs.begin(), new_decs.end() );
    }

    pop_error_context() ;
    return create_class_var_decs(class_declarations) ;
}

// static_var_dec ::= 'static' type identifier (',' identifier)* ';'
// returns vector of ast_var_dec
//
// ast_var_dec: create_var_dec(string name,string segment,int offset,string type)
// create_var_dec must be passed:
// . name: the variable's name
// . segment: the variable's segment
// . offset: the variable's position in it's segment
// . type: the variable's type
//
vector<ast> parse_static_var_dec()
{
    vector<ast> decs ;
    push_error_context("parse_class()") ;

    mustbe(tk_static);

    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "static"; ///////////////////////////////////////////////////////////////////////

    int offset = declare_variable(name, type, segment);
    decs.push_back( create_var_dec(name, segment, offset, type) );

    while ( have( current_token(), tk_comma ) )
    {
        mustbe(tk_comma);
        name = token_spelling( mustbe(tk_identifier) );
        segment = "static";

        offset = declare_variable(name, type, segment);
        decs.push_back( create_var_dec(name, segment, offset, type) );
    }

    mustbe(tk_semi);

    pop_error_context() ;
    return decs ;
}

// field_var_dec ::= 'field' type identifier (',' identifier)* ';'
// returns vector of ast_var_dec
//
// ast_var_dec: create_var_dec(string name,string segment,int offset,string type)
// create_var_dec must be passed:
// . name: the variable's name
// . segment: the variable's segment
// . offset: the variable's position in it's segment
// . type: the variable's type
//
vector<ast> parse_field_var_dec()
{
    vector<ast> decs ;
    push_error_context("parse_class()") ;

    mustbe(tk_field);

    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "field"; ////////////////////////////////////////////////////////////

    int offset = declare_variable(name, type, segment);
    decs.push_back( create_var_dec(name, segment, offset, type) );

    while ( have( current_token(), tk_comma ) )
    {
        mustbe(tk_comma);
        name = token_spelling( mustbe(tk_identifier) );
        segment = "field";

        offset = declare_variable(name, type, segment);
        decs.push_back( create_var_dec(name, segment, offset, type) );
    }

    mustbe(tk_semi);

    pop_error_context() ;
    return decs ;
}

// type ::= 'int' | 'char' | 'boolean' | identifier
// returns the Token for the type
Token parse_type()
{
    push_error_context("parse_type()") ;

    Token type;

    if ( have( current_token(), tk_int ) )
    {
        type = tk_int;
    }

    else if ( have( current_token(), tk_char ) )
    {
        type = tk_char;
    }

    else if ( have( current_token(), tk_boolean ) )
    {
        type = tk_boolean;
    }

    else if ( have( current_token(), tk_identifier ) )
    {
        type = tk_identifier;
    }

    pop_error_context() ;
    return type ;
}

// vtype ::= 'void' | type
// returns the Token for the type
Token parse_vtype()
{
    push_error_context("parse_vtype()") ;

    Token type;

    if ( have( current_token(), tk_void ) )
    {
        type = tk_void;
    }

    else if ( have( current_token(), tk_type ) )
    {
        type = parse_type();
    }

    pop_error_context() ;
    return type ;
}

// subr_decs ::= (constructor | function | method)*
// returns ast_subr_decs: create_subr_decs(vector<ast> subrs)
// create_subr_decs must be passed an vector of ast_subr
//
// ast_subr: create_subr(ast subr)
// create_subr must be passed one of: ast_constructor, ast_function or ast_method
//
ast parse_subr_decs()
{
    push_error_context("parse_subr_decs()") ;

    vector<ast> subrs;
    while( have( current_token(), tk_subroutine) )
    {
        if ( have( current_token(), tk_constructor ) )
        {
            subrs.push_back( create_subr( parse_constructor() ) );
        }
        else if ( have( current_token(), tk_function ) )
        {
            subrs.push_back( create_subr( parse_function() ) );
        }
        else if ( have( current_token(), tk_method ) )
        {
            subrs.push_back( create_subr( parse_method() ) );
        }

    }

    pop_error_context() ;
    return create_subr_decs(subrs) ;
}

// constructor ::= 'constructor' identifier identifier '(' param_list ')' subr_body
// returns ast_constructor: create_constructor(string vtype,string name,ast params,ast body)
// . vtype: the constructor's return type, this must be it's class name
// . name: the constructor's name within its class
// . params: ast_param_list - the constructor's parameters
// . body: ast_subr_body - the constructor's body
//
ast parse_constructor()
{
    push_error_context("parse_constructor()") ;

    function_symbol_table = create_variables();
    function_offset = 0;

    mustbe(tk_constructor);
    string type = token_spelling( parse_vtype() );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();

    delete_variables(function_symbol_table);

    pop_error_context() ;
    return create_constructor(type, name, parameters, body) ;
}

// function ::= 'function' vtype identifier '(' param_list ')' subr_body
// returns ast_function: create_function(string vtype,string name,ast params,ast body)
// . vtype: the function's return type
// . name: the function's name within its class
// . params: ast_param_list - the function's parameters
// . body: ast_subr_body - the function's body
//
ast parse_function()
{
    push_error_context("parse_function()") ;

    function_symbol_table = create_variables();
    function_offset = 0;

    mustbe(tk_function);
    string type = token_spelling( mustbe(tk_vtype) );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();


    delete_variables(function_symbol_table);

    pop_error_context() ;
    return create_function(type, name, parameters, body) ;
}

// method ::= 'method' vtype identifier '(' param_list ')' subr_body
// returns ast_method: create_method(string vtype,string name,ast params,ast body)
// . vtype: the method's return type
// . name: the method;s name within its class
// . params: ast_param_list - the method's explicit parameters
// . body: ast_subr_body - the method's body
//
ast parse_method()
{
    push_error_context("parse_method()") ;

    function_symbol_table = create_variables();
    function_offset = 0;

    mustbe(tk_method);
    string type = token_spelling( parse_vtype() );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();

    delete_variables(function_symbol_table);

    pop_error_context() ;
    return create_method(type, name, parameters, body) ;
}

// param_list ::= ((type identifier) (',' type identifier)*)?
// returns ast_param_list: create_param_list(vector<ast> params)
// create_param_list must be passed a vector of ast_var_dec
//
// ast_var_dec: create_var_dec(string name,string segment,int offset,string type)
// create_var_dec must be passed:
// . name: the variable's name
// . segment: the variable's segment
// . offset: the variable's position in it's segment
// . type: the variable's type
//
ast parse_param_list()
{
    push_error_context("parse_param_list()") ;

    vector<ast> parameters;

    if ( have( current_token(), tk_type ) )
    {
        string type = token_spelling( current_token() );
        next_token();
        string name = token_spelling( mustbe(tk_identifier) );
        string segment = "local test";
        int offset = 0;

        parameters.push_back( create_var_dec(name, segment, offset, type) );

        while ( current_token() == tk_type )
        {
            mustbe(tk_comma);
            type = token_spelling( current_token() );
            next_token();
            name = token_spelling( mustbe(tk_identifier) );
            segment = "local test"; ////////////////////////////////////////////////////////////////////
            offset = 0;

            parameters.push_back( create_var_dec(name, segment, offset, type) );
        }
    }

    pop_error_context() ;
    return create_param_list(parameters) ;
}

// subr_body ::= '{' var_decs statements '}'
// returns ast_subr_body: create_subr_body(ast decs,ast body)
// create_subr_body must be passed:
// . decs: ast_var_decs - the subroutine's local variable declarations
// . body: ast_statements - the statements within the body of the subroutinue
//
ast parse_subr_body()
{
    push_error_context("parse_subr_body()") ;

    mustbe(tk_lcb);

    ast var_decs = parse_var_decs();
    ast statements = parse_statements();

    mustbe(tk_rcb);

    pop_error_context() ;
    return create_subr_body(var_decs, statements) ;
}

// var_decs ::= var_dec*
// returns ast_var_decs: create_var_decs(vector<ast> decs)
// create_var_decs must be passed a vector of ast_var_dec
//
ast parse_var_decs()
{
    push_error_context("parse_var_decs()") ;

    vector<ast> declarations;

    //CHANGING THIS CAUSES CRASHES
    Token exist = current_token();
    while( have(exist, tk_var))
    {

        vector<ast> new_decs = parse_var_dec();
        declarations.insert( declarations.end(), new_decs.begin(), new_decs.end() );

        exist = next_token();
    }

    pop_error_context() ;
    return create_var_decs(declarations) ;
}

// var_dec ::= 'var' type identifier (',' identifier)* ';'
// returns vector of ast_var_dec
//
// ast_var_dec: create_var_dec(string name,string segment,int offset,string type)
// create_var_dec must be passed:
// . name: the variable's name
// . segment: the variable's segment
// . offset: the variable's position in it's segment
// . type: the variable's type
//
vector<ast> parse_var_dec()
{
    vector<ast> decs ;
    push_error_context("parse_var_dec()") ;

    mustbe(tk_var);
    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "0"; ////////////////////////////////////////////////////////////////////////////////////////////////////////
    int offset = 0;

    decs.push_back( create_var_dec(name, segment, offset, type) );

    Token exist = current_token();
    while( have(exist, tk_comma) )
    {
        next_token();
        name = mustbe(tk_identifier);
        segment = "0";
        offset = 0;
        decs.push_back( create_var_dec(name, segment, offset, type) );
        exist = current_token();
    }

    mustbe(tk_semi);

    pop_error_context() ;
    return decs ;
}

// statements ::= statement*
// create_statements(vector<ast> statements)
// create_statements must be passed a vector of ast_statement
//
ast parse_statements()
{
    push_error_context("parse_statements()") ;

    vector<ast> statements;

    while( have( current_token(), tk_statement) )
    {
        statements.push_back( parse_statement() );
    }

    pop_error_context() ;
    return create_statements(statements) ;
}

// statement ::= let | if | while | do | return
// create_statement(ast statement)
// create_statement initialiser must be one of: ast_let, ast_let_array, ast_if, ast_if_else, ast_while, ast_do, ast_return or ast_return_expr
//
ast parse_statement()
{
    push_error_context("parse_statement()") ;

    ast statement;
    Token type = current_token();

    if ( have(type, tk_let) )
    {
        statement = parse_let();
    }

    if ( have(type, tk_if) )
    {
        statement = parse_if();
    }

    else if ( have(type, tk_while) )
    {
        statement = parse_while();
    }

    else if ( have(type, tk_do) )
    {
        statement = parse_do();
    }

    else if ( have(type, tk_return) )
    {
        statement = parse_return();
    }

    pop_error_context() ;
    return create_statement(statement) ;
}

// let ::= 'let' identifier index? '=' expr ';'
// return one of: ast_let or ast_let_array
//
// create_let(ast var,ast expr)
// . var: ast_var - the variable being assigned to
// . expr: ast_expr - the variable's new value
//
// create_let_array(ast var,ast index,ast expr)
// . var: ast_var - the variable for the array being assigned to
// . index: ast_expr - the array index
// . expr: ast_expr - the array element's new value
//
ast parse_let()
{
    push_error_context("parse_let()") ;

    bool array = false;

    mustbe(tk_let);
    Token variable = mustbe(tk_identifier);
    ast var; ////////////////////////////////////////////////////////////////////////////////////////
    ast new_index;
    if ( have( current_token(), tk_lsb ) )
    {
        new_index = parse_index();
        array = true;
    }
    mustbe(tk_eq);
    ast new_expression = parse_expr(); ////////////////////////////////////////////////////////////////
    mustbe(tk_semi);

    pop_error_context() ;
    return -1; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    if (array == true)
    {
        return create_let(var, new_expression);
    }
    else
    {
        return create_let_array(var, new_index, new_expression);
        //return -1;
    }
}

// if ::= 'if' '(' expr ')' '{' statements '}' ('else' '{' statements '}')?
// return one of: ast_if or ast_if_else
//
// create_if(ast condition,ast if_true)
// . condition: ast_expr - the if condition
// . if_true: ast_statements - the if true branch
//
// create_if_else(ast condition,ast if_true,ast if_false)
// . condition: ast_expr - the if condition
// . if_true: ast_statements - the if true branch
// . if_false: ast_statements - the if false branch
//
ast parse_if()
{
    push_error_context("parse_if()") ;

    mustbe(tk_if);
    mustbe(tk_lrb);

    ast condition = parse_expr();

    mustbe(tk_rrb);
    mustbe(tk_lcb);

    ast statement_true = parse_statements();

    mustbe(tk_rcb);

    if ( have( current_token(), tk_else) )
    {
        mustbe(tk_else);
        mustbe(tk_lcb);

        ast statement_false = parse_statements();

        mustbe(tk_rcb);

        pop_error_context() ;
        return create_if_else(condition, statement_true, statement_false);
    }

    pop_error_context() ;
    return create_if(condition, statement_true) ;
}

// while ::= 'while' '(' expr ')' '{' statements '}'
// returns ast_while: create_while(ast condition,ast body)
// . condition: ast_expr - the loop condition
// . body: ast_statements - the loop body
//
ast parse_while()
{
    push_error_context("parse_while()") ;

    mustbe(tk_while);
    mustbe(tk_lrb);
    ast expression = parse_expr();
    mustbe(tk_rrb);
    mustbe(tk_lcb);
    ast statements = parse_statements();
    mustbe(tk_rcb);

    pop_error_context() ;
    return create_while(expression, statements) ;
}

// do ::= 'do' identifier (call | id_call) ';'
// returns ast_do: create_do(ast call)
// create_do must be passed one of: ast_call_as_function or ast_call_as_method
//
// ast_call_as_function: create_call_as_function(string class_name,ast subr_call)
// create_ast_call_as_function must be passed:
// . class_name: name of the function's class
// . subr_call: ast_subr_call - the function's name within it's class and it's explicit arguments
//
// ast_call_as_method: create_call_as_method(string class_name,ast object,ast subr_call)
// create_ast_call_as_method must be passed:
// . class_name: name of the method's class
// . object: ast_expr - the object the method is applied to
// . subr_call: ast_subr_call - the method's name within it's class and it's explicit arguments
//
ast parse_do()
{
    push_error_context("parse_do()") ;

    mustbe(tk_do);
    string name = token_spelling( mustbe(tk_identifier) );
    //////////////////////////////////////////////////////////////////////////////////////////
    ast call;

    pop_error_context() ;
    return create_do(call) ;
}

// return ::= 'return' expr? ';'
// returns one of: ast_return or ast_return_expr
//
// ast_return: create_return()
//
// ast_return_expr: create_return_expr(ast expr)
// create_return_expr must be passed an ast_expr
//
ast parse_return()
{
    push_error_context("parse_return()") ;

    mustbe(tk_return);

    if ( have( current_token(), tk_semi) )
    {
        next_token();
        pop_error_context() ;
        return create_return() ;
    }

    ast expr = parse_expr();
    mustbe(tk_semi);

    pop_error_context() ;

    return create_return_expr(expr);
}

// expr ::= term (infix_op term)*
// returns ast_expr: create_expr(vector<ast> expr)
// the vector passed to create_expr:
// . must be an odd length of at least 1, ie 1, 3, 5, ...
// . must be  a vector alternating between ast_term and ast_infix_op nodes, ending with an ast_term
//
ast parse_expr()
{
    push_error_context("parse_expr()") ;

    vector<ast> expressions;

    expressions.push_back( parse_term() );
    while ( have( current_token(), tk_infix_op ) )
    {
        expressions.push_back( parse_infix_op() );
        expressions.push_back( parse_term() );
    }

    pop_error_context() ;
    return create_expr(expressions) ;
}

// term ::= integer_constant | string_constant | 'true' | 'false' | 'null' | 'this' | '(' expr ')' | unary_op term | var_term
// returns ast_term: create_term(ast term)
// create_term must be passed one of: ast_int, ast_string, ast_bool, ast_null, ast_this, ast_expr,
//                                    ast_unary_op, ast_var, ast_array_index, ast_call_as_function, ast_call_as_method
//
// ast_int: create_int(int _constant)
// create_int must be passed an integer value in the range 0 to 32767
//
// ast_string: create_string(string _constant)
// create_string must be passed any legal Jack string literal
//
// ast_bool: create_bool(bool t_or_f)
// create_bool must be passed true or false
//
// ast_null: create_null()
//
// ast_this: create_this()
//
// ast_unary_op: create_unary_op(string op,ast term)
// create_unary_op must be passed:
// . op: the unary op
// . term: ast_term
//
ast parse_term()
{
    push_error_context("parse_term()") ;

    ast term;
    ast nextTerm;

    if ( have( current_token(), tk_integerConstant ) )
    {
        string number = token_spelling( current_token() );
        stringstream convert(number);
        int constant = 0;
        convert >> constant;
        term = create_int(constant);
        next_token();
    }

    else if ( have( current_token(), tk_stringConstant ) )
    {
        string literal = token_spelling( current_token() );
        term = create_string(literal);
        next_token();
    }

    else if ( have( current_token(), tk_true ) )
    {
        term = create_bool(true);
        next_token();
    }

    else if ( have( current_token(), tk_false ) )
    {
        term = create_bool(false);
        next_token();
    }

    else if ( have( current_token(), tk_null ) )
    {
        term = create_null();
        next_token();
    }

    else if ( have( current_token(), tk_this ) )
    {
        term = create_this();
        next_token();
    }

    else if ( have( current_token(), tk_lrb ) )
    {
        mustbe(tk_lrb);
        term = parse_expr();
        mustbe(tk_rrb);
    }

    else if ( have( current_token(), tk_unary_op ) )
    {
        string op = token_spelling( current_token() );
        nextTerm = parse_term();
        term = create_unary_op(op, nextTerm);
    }

    else if ( have( current_token(), tk_identifier ) )
    {
        term = parse_var_term();
        //Test 08 ???????????????????????????????????????????????????????????????????
    }

    pop_error_context() ;
    return create_term(term) ;
}

// var_term ::= identifier (index | id_call | call)?
// returns one of: ast_var, ast_array_index, ast_call_as_function or ast_call_as_method
//
// ast_var: create_var(string name,string segment,int offset,string type)
// create_ast_var must be passed:
// . name: the variable's name
// . segment: the variable's segment
// . offset: the variable's position in it's segment
// . type: the variable's type
//
// ast_array_index: create_array_index(ast var,ast index)
// create_ast_array_index must be passed:
// . var: ast_var - the array variable
// . index: ast_expr - the index into the array
//
// ast_call_as_function: create_call_as_function(string class_name,ast subr_call)
// create_ast_call_as_function must be passed:
// . class_name: name of the function's class
// . subr_call: ast_subr_call - the function's name within it's class and it's explicit arguments
//
// ast_call_as_method: create_call_as_method(string class_name,ast object,ast subr_call)
// create_ast_call_as_method must be passed:
// . class_name: name of the method's class
// . object: ast_expr - the object the method is applied to
// . subr_call: ast_subr_call - the method's name within it's class and it's explicit arguments
//
ast parse_var_term()
{
    push_error_context("parse_var_term()") ;

    ast var_term;

    string name = token_spelling( mustbe(tk_identifier) );
    if ( have( current_token(), tk_lsb ) )
    {
        var_term = parse_index(); ///////////////////////////////////////// I think I need more here
    }
    else if ( have( current_token(), tk_stop ) )
    {
        var_term = parse_id_call();
        return create_call_as_function(name, var_term);
    }
    else if ( have( current_token(), tk_lrb ) )
    {
        var_term = parse_call();
        //return create_call_as_method(name, ast object, var_term); ///////////////////Unsure about name
    }

    pop_error_context() ;
    return -1 ;
}

// index ::= '[' expr ']'
// returns ast_expr
ast parse_index()
{
    push_error_context("parse_index()") ;

    mustbe(tk_lsb);
    ast expression = parse_expr();
    mustbe(tk_rsb);

    pop_error_context() ;
    return expression ;
}

// id_call ::= '.' identifier call
// returns ast_subr_call: create_subr_call(string subr_name,ast expr_list)
// create_subr_call must be passed:
// . subr_name: the constructor, function or method's name within its class
// . expr_list: ast_expr_list - the explicit arguments to the call
//
ast parse_id_call()
{
    push_error_context("parse_id_call()") ;

    mustbe(tk_stop);
    string name = token_spelling( mustbe(tk_identifier) );
    ast call = parse_call();

    pop_error_context() ;
    return create_subr_call(name, call) ;
}

// call ::= '(' expr_list ')'
// returns ast_expr_list
//
ast parse_call()
{
    push_error_context("parse_call()") ;

    mustbe(tk_lrb);
    ast expression_list = parse_expr_list();
    mustbe(tk_rrb);

    pop_error_context() ;
    return expression_list ;
}

// expr_list ::= (expr (',' expr)*)?
// returns ast_expr_list: create_expr_list(vector<ast> exprs)
// create_expr_list must be passed: a vector of ast_expr
//
ast parse_expr_list()
{
    push_error_context("parse_expr_list()") ;

    vector<ast> expression_list;

    if ( have( current_token(), tk_term) )
    {
        expression_list.push_back( parse_expr() );
        while ( have( current_token(), tk_comma ) )
        {
            mustbe(tk_comma);
            expression_list.push_back( parse_expr() );
        }
    }

    pop_error_context() ;
    return create_expr_list(expression_list) ;
}

// infix_op ::= '+' | '-' | '*' | '/' | '&' | '|' | '<' | '>' | '='
// returns ast_op: create_infix_op(string infix_op)
// create_infix_op must be passed:
// infix_op: the infix op
//
ast parse_infix_op()
{
    push_error_context("parse_infix_op()") ;

    Token infix_oper = mustbe(tk_infix_op);
    string op = token_spelling(infix_oper);

    pop_error_context() ;
    return create_infix_op(op) ;
}

// unary_op ::= '-' | '~'
// returns Token for the unary_op
//
Token parse_unary_op()
{
    push_error_context("parse_unary_op()") ;

    Token type;

    if ( have( current_token(), tk_sub ) )
    {
        type = mustbe(tk_sub);
    }

    else if ( have( current_token(), tk_not ) )
    {
        type = mustbe(tk_not);
    }

    pop_error_context() ;
    return type ;
}

ast jack_parser()
{
    // read the first token to get the tokeniser initialised
    next_token() ;

    // construct tree and return as result
    return parse_class() ;
}

// main program
int main(int argc,char **argv)
{
    // parse a Jack class and print the abstract syntax tree as XML
    ast_print_as_xml(jack_parser(),4) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}
