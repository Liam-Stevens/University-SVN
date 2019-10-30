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

//Symbol Table and offset information
symbols class_symbol_table;
int class_offset[2];
string class_name;
symbols function_symbol_table;
int function_offset[3];

//Put a variable into the symbol table and return its offset
int declare_variable(string name, string type, string segment)
{
    //Forward declaration of variables
    symbols symbol_table;
    int offset;

    //Put into class symbol table
    if (segment == "static" || segment == "field")
    {
        symbol_table = class_symbol_table;
        //Static Variable
        if (segment == "static")
        {
            offset = class_offset[0];
            class_offset[0]++;
        }
        //Field Variable
        else
        {
            offset = class_offset[1];
            class_offset[1]++;
        }
    }
    //Put into function symbol table
    else if (segment == "local" || segment == "argument")
    {
        symbol_table = function_symbol_table;
        //Local Variable
        if (segment == "local")
        {
            offset = function_offset[0];
            function_offset[0]++;
        }
        //Argument Variable
        else
        {
            offset = function_offset[1];
            function_offset[1]++;
        }
    }
    //Created to handle anything unexpected
    else
    {
        symbol_table = function_symbol_table;
        offset = function_offset[2];
        function_offset[2]++;
    }

    //Creates the variable and puts it into the table
    st_variable new_var(name, type, segment, offset);
    insert_variables(symbol_table, name, new_var);

    return offset;
}

//Does a variable lookup from the symbol table
st_variable lookup_variable(string name)
{
    //Look in the class symbol table
    st_variable temp = lookup_variables(class_symbol_table, name);
    //Look in the function symbol table
    if (temp.offset == -1)
    {
        temp = lookup_variables(function_symbol_table, name);
    }
    //In the case that the variable does not exist
    if (temp.offset == -1)
    {
        fatal_error(0,"Could not find variable") ;
    }

    return temp;
}

//Returns an ast for a variable lookup
ast get_variable(string name)
{
    //Does the lookup on both tables
    st_variable temp = lookup_variables(class_symbol_table, name);
    if (temp.offset == -1)
    {
        temp = lookup_variables(function_symbol_table, name);
    }

    //Creates a generic variable for return in the case of failure
    if (temp.offset == -1)
    {
        string segment = "local";
        int offset = 0;
        string type = "Array";

        declare_variable(name, type, segment);

        ast variable = create_var(name, segment, offset, type);
        return variable;
    }
    //Returns a ast for the variable looked up
    else
    {
        string segment = temp.segment;
        int offset = temp.offset;
        string type = temp.type;

        ast variable = create_var(name, segment, offset, type);
        return variable;
    }

}

//Resets the offset counters for a respective table
void clean_table(string table)
{
    //Class variable table
    if (table == "class")
    {
        class_offset[0] = 0;
        class_offset[1] = 0;
    }
    //Function variable table
    else if (table == "function")
    {
        function_offset[0] = 0;
        function_offset[2] = 0;
    }
}

// class ::= 'class' identifier '{' class_var_decs subr_decs '}'
// create_class(myclassname,class_var_decs,class_subrs)
//Parses a class
ast parse_class()
{
    push_error_context("parse_class()") ;

    //Creates the first symbol table
    class_symbol_table = create_variables();
    clean_table("class");

    //Parses according to the syntax
    mustbe(tk_class);
    class_name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lcb);

    ast class_var = parse_class_var_decs();
    ast subr_decs = parse_subr_decs();

    mustbe(tk_rcb);

    //Deletes the symbol table
    delete_variables(class_symbol_table);

    pop_error_context() ;
    return create_class(class_name,class_var,subr_decs) ;
}

// class_var_decs ::= (static_var_dec | field_var_dec)*
// returns ast_class_var_decs: create_class_var_decs(vector<ast> decs)
// create_class_var_decs must be passed a vector of ast_var_dec
//
//Parses class variable declarations
ast parse_class_var_decs()
{
    push_error_context("parse_class_var_decs()") ;

    vector<ast> class_declarations;

    //While there are variable declarations
    while( have( current_token(), tk_class_var ) )
    {
        vector<ast> new_decs;
        //Static Variable
        if ( have( current_token(), tk_static ) )
        {
            new_decs = parse_static_var_dec();
        }
        //Field Variable
        else if ( have( current_token(), tk_field ) )
        {
            new_decs = parse_field_var_dec();
        }
        //Error Handling
        else
        {
            fatal_error(0,"Bad Token") ;
        }

        //Concatenates temporary vector to the end of the main vector
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
//Parses static variable declarations
vector<ast> parse_static_var_dec()
{
    push_error_context("parse_class()") ;

    mustbe(tk_static);
    vector<ast> decs ;

    //Gets the variable information
    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "static";
    //Puts the variable into the symbol table and pushes to the vector
    int offset = declare_variable(name, type, segment);
    decs.push_back( create_var_dec(name, segment, offset, type) );

    while ( have( current_token(), tk_comma ) )
    {
        //Gets additional names
        mustbe(tk_comma);
        name = token_spelling( mustbe(tk_identifier) );
        //Puts the variable into the symbol table and pushes to the vector
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
//Parses field variable declarations
vector<ast> parse_field_var_dec()
{
    push_error_context("parse_class()") ;

    mustbe(tk_field);
    vector<ast> decs ;

    //Gets the variable information
    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "this";
    //Puts the variable into the symbol table and pushes to the vector
    int offset = declare_variable(name, type, segment);
    decs.push_back( create_var_dec(name, segment, offset, type) );

    //While additional declarations
    while ( have( current_token(), tk_comma ) )
    {
        mustbe(tk_comma);
        //Gets additional names
        name = token_spelling( mustbe(tk_identifier) );
        //Puts the variable into the symbol table and pushes to the vector
        offset = declare_variable(name, type, segment);
        decs.push_back( create_var_dec(name, segment, offset, type) );
    }

    mustbe(tk_semi);

    pop_error_context() ;
    return decs ;
}

// type ::= 'int' | 'char' | 'boolean' | identifier
// returns the Token for the type
//Parses a type
Token parse_type()
{
    push_error_context("parse_type()") ;

    Token type = mustbe(tk_type);

    pop_error_context() ;
    return type ;
}

// vtype ::= 'void' | type
// returns the Token for the type
//Parses a vtype
Token parse_vtype()
{
    push_error_context("parse_vtype()") ;

    Token type = mustbe(tk_vtype);

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
//Parses the subroutine declarations
ast parse_subr_decs()
{
    push_error_context("parse_subr_decs()") ;

    vector<ast> subrs;
    //While there are subroutines
    while( have( current_token(), tk_subroutine) )
    {
        //Constructor
        if ( have( current_token(), tk_constructor ) )
        {
            subrs.push_back( create_subr( parse_constructor() ) );
            function_offset[1] = 1;
        }
        //Function
        else if ( have( current_token(), tk_function ) )
        {
            subrs.push_back( create_subr( parse_function() ) );
            function_offset[1] = 0;
        }
        //Method
        else if ( have( current_token(), tk_method ) )
        {
            subrs.push_back( create_subr( parse_method() ) );
            function_offset[1] = 1;
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
//Parses a constructor
ast parse_constructor()
{
    push_error_context("parse_constructor()") ;

    //Creates a second symbol table
    function_symbol_table = create_variables();
    clean_table("function");

    //Parses constructor according to syntax
    mustbe(tk_constructor);
    string type = token_spelling( mustbe(tk_identifier) );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();

    //Deletes the second symbol table
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
//Parses a function
ast parse_function()
{
    push_error_context("parse_function()") ;

    //Creates a second symbol table
    function_symbol_table = create_variables();
    clean_table("function");

    //Parses function according to syntax
    mustbe(tk_function);
    string type = token_spelling( mustbe(tk_vtype) );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();

    //Deletes the function symbol table
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
//Parses a method
ast parse_method()
{
    push_error_context("parse_method()") ;

    //Creates a second symbol table
    function_symbol_table = create_variables();
    clean_table("function");

    //Parses method according to syntax
    mustbe(tk_method);
    string type = token_spelling( parse_vtype() );
    string name = token_spelling( mustbe(tk_identifier) );
    mustbe(tk_lrb);
    ast parameters = parse_param_list();
    mustbe(tk_rrb);
    ast body = parse_subr_body();

    //Deletes the second symbol table
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
//Parse a parameter list
ast parse_param_list()
{
    push_error_context("parse_param_list()") ;

    vector<ast> parameters;

    //Check for any parameters
    if ( have( current_token(), tk_type ) )
    {
        //Gets information for the variable
        string type = token_spelling( mustbe(tk_type));
        string name = token_spelling( mustbe(tk_identifier) );
        string segment = "argument";
        //Puts variable into symbol table
        int offset = declare_variable(name, type, segment);
        //Pushes variable into vector
        parameters.push_back( create_var_dec(name, segment, offset, type) );

        //While there are any additional parameters
        while ( have( current_token(), tk_comma) )
        {
            //Gets variable information
            mustbe(tk_comma);
            type = token_spelling( mustbe(tk_type) );
            name = token_spelling( mustbe(tk_identifier) );
            segment = "argument";
            //Puts variable into symbol table and pushes to vector
            offset = declare_variable(name, type, segment);
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
//Parse Subroutine Body
ast parse_subr_body()
{
    push_error_context("parse_subr_body()") ;

    //Parses it according to the syntax
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
//Parses multiple types of variable declarations
ast parse_var_decs()
{
    push_error_context("parse_var_decs()") ;

    vector<ast> declarations;

    //While there are variables
    while( have( current_token(), tk_var ) )
    {
        //Create a tmp vector
        vector<ast> new_decs;
        new_decs = parse_var_dec();
        //Concatenate new vector to the end of the main vector
        declarations.reserve(new_decs.size());
        declarations.insert( declarations.end(), new_decs.begin(), new_decs.end() );
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
//Parses variable declarations
vector<ast> parse_var_dec()
{
    push_error_context("parse_var_dec()") ;

    vector<ast> decs ;

    //Set all variable information
    mustbe(tk_var);
    string type = token_spelling( mustbe(tk_type) );
    string name = token_spelling( mustbe(tk_identifier) );
    string segment = "local";

    //Put variable into symbol table
    int offset = declare_variable(name, type, segment);;
    //Push declaration to vector
    decs.push_back( create_var_dec(name, segment, offset, type) );

    //While there are more variable declaration
    while( have( current_token(), tk_comma) )
    {
        mustbe(tk_comma);
        name = token_spelling( mustbe(tk_identifier) );
        segment = "local";
        //Put variable into symbol table and push to vector
        offset = declare_variable(name, type, segment);
        decs.push_back( create_var_dec(name, segment, offset, type) );
    }

    mustbe(tk_semi);

    pop_error_context() ;
    return decs ;
}

// statements ::= statement*
// create_statements(vector<ast> statements)
// create_statements must be passed a vector of ast_statement
//
//Parses multiple statements
ast parse_statements()
{
    push_error_context("parse_statements()") ;

    vector<ast> statements;

    //Pushses statements to vector while there are statements
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
//Parses a statement declaration
ast parse_statement()
{
    push_error_context("parse_statement()") ;

    //Forward declaration
    ast statement;

    //This must be here, as the code fails if type is replaced with current_token in the have functions
    Token type = current_token();

    //Let statement
    if ( have( type, tk_let ) )
    {
        statement = parse_let();
    }
    //If Statement
    if ( have( type, tk_if ) )
    {
        statement = parse_if();
    }
    //While Statement
    else if ( have( type, tk_while ) )
    {
        statement = parse_while();
    }
    //Do Statement
    else if ( have( type, tk_do ) )
    {
        statement = parse_do();
    }
    //Return Statement
    else if ( have( type, tk_return ) )
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
//Parses a let statement
ast parse_let()
{
    push_error_context("parse_let()") ;

    bool array = false;

    //Let statement syntax
    mustbe(tk_let);
    string var_name = token_spelling( mustbe(tk_identifier) );
    ast var = get_variable(var_name);
    ast new_index;

    //Check for an array index
    if ( have( current_token(), tk_lsb ) )
    {
        new_index = parse_index();
        array = true;
    }

    mustbe(tk_eq);
    ast new_expression = parse_expr();
    mustbe(tk_semi);

    pop_error_context() ;

    //Creates let depending on if there was an array
    if (array == false)
    {
        return create_let(var, new_expression);
    }
    else
    {
        return create_let_array(var, new_index, new_expression);
    }
    return -1;
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
//Parses an if statement
ast parse_if()
{
    push_error_context("parse_if()") ;

    //Check for If statement syntax
    mustbe(tk_if);

    mustbe(tk_lrb);
    ast condition = parse_expr();
    mustbe(tk_rrb);

    mustbe(tk_lcb);
    ast statement_true = parse_statements();
    mustbe(tk_rcb);

    //Check for the else statement
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
//Parse a while loop
ast parse_while()
{
    push_error_context("parse_while()") ;

    //Parses for while syntax
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
//Parses a do call
ast parse_do()
{
    push_error_context("parse_do()") ;

    mustbe(tk_do);
    string name = token_spelling( mustbe(tk_identifier) );

    //Forward declaration of asts
    ast call;
    ast sub_call;
    ast object;

    //Check for an ID call
    if ( have( current_token(), tk_stop ) )
    {
        sub_call = parse_id_call();

        //Get variable from class table
        st_variable temp = lookup_variables(class_symbol_table, name);
        //Get variable from function table
        if (temp.offset == -1)
        {
            temp = lookup_variables(function_symbol_table, name);
        }
        //If not variable, call all is a function
        if (temp.offset == -1)
        {
            call = create_call_as_function(name, sub_call);
        }
        else
        {
            //Get variable information and create variable
            string segment = temp.segment;
            int offset = temp.offset;
            string type = temp.type;
            object = create_var(name, segment, offset, type);

            call = create_call_as_method(type, object, sub_call);
        }

    }
    //Check for a call
    else if ( have( current_token(), tk_lrb ) )
    {
        //Parses the call
        sub_call = create_subr_call(name, parse_call() );
        object = create_this();
        call = create_call_as_method(class_name, object, sub_call);
    }

    mustbe(tk_semi);

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
//Parses a return call
ast parse_return()
{
    push_error_context("parse_return()") ;

    //Return
    mustbe(tk_return);

    //Check if the return is ending
    if ( have( current_token(), tk_semi) )
    {
        mustbe(tk_semi);
        pop_error_context() ;
        return create_return() ;
    }

    //Parses the expression if the return is not ending
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
//Parses an expression
ast parse_expr()
{
    push_error_context("parse_expr()") ;

    vector<ast> expressions;

    //Push term into the vector
    expressions.push_back( parse_term() );
    //Push any additional expressions into the vector
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
//Parses a term
ast parse_term()
{
    push_error_context("parse_term()") ;

    //Forward declaration of asts
    ast term;
    ast nextTerm;

    //Integer Constant
    if ( have( current_token(), tk_integerConstant ) )
    {
        //String streams the number from a string to an int
        string number = token_spelling( mustbe(tk_integerConstant) );
        stringstream convert(number);
        int constant = 0;
        convert >> constant;
        term = create_int(constant);
    }
    //String Constant
    else if ( have( current_token(), tk_stringConstant ) )
    {
        string literal = token_spelling( mustbe(tk_stringConstant) );
        term = create_string(literal);
    }
    //True
    else if ( have( current_token(), tk_true ) )
    {
        mustbe(tk_true);
        term = create_bool(true);
    }
    //False
    else if ( have( current_token(), tk_false ) )
    {
        mustbe(tk_false);
        term = create_bool(false);
    }
    //Null
    else if ( have( current_token(), tk_null ) )
    {
        mustbe(tk_null);
        term = create_null();
    }
    //This
    else if ( have( current_token(), tk_this ) )
    {
        mustbe(tk_this);
        term = create_this();
    }
    //Expression
    else if ( have( current_token(), tk_lrb ) )
    {
        mustbe(tk_lrb);
        term = parse_expr();
        mustbe(tk_rrb);
    }
    //Unary Operator
    else if ( have( current_token(), tk_unary_op ) )
    {
        string op = token_spelling( mustbe(tk_unary_op) );
        nextTerm = parse_term();
        term = create_unary_op(op, nextTerm);
    }
    //Variable Term
    else if ( have( current_token(), tk_identifier ) )
    {
        term = parse_var_term();
    }
    //Push error if it wasn't a term
    else
    {
        mustbe(tk_term);
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
//Parses a variable term
ast parse_var_term()
{
    push_error_context("parse_var_term()") ;

    //Forward declaration of asts
    ast var_term;
    ast variable;
    ast object;

    string name = token_spelling( mustbe(tk_identifier) );

    //Parse for index
    if ( have( current_token(), tk_lsb ) )
    {
        var_term = parse_index();
        variable = get_variable(name);

        pop_error_context() ;
        return create_array_index(variable, var_term);
    }
    //Parse for id call
    else if ( have( current_token(), tk_stop ) )
    {
        //function
        ast sub_call = parse_id_call();

        //Check if there is a variable in the class symbol table
        st_variable temp = lookup_variables(class_symbol_table, name);
        //Check function symbol table
        if (temp.offset == -1)
        {
            temp = lookup_variables(function_symbol_table, name);
        }
        //If no variable, call is a function
        if (temp.offset == -1)
        {
            return create_call_as_function(name, sub_call);
        }

        //Get variable information and create variable
        string segment = temp.segment;
        int offset = temp.offset;
        string type = temp.type;
        object = create_var(name, segment, offset, type);

        return create_call_as_method(type, object, sub_call);

    }
    //Parse for call
    else if ( have( current_token(), tk_lrb ) )
    {
        ast sub_call = create_subr_call(name, parse_call() );
        object = create_this();
        return create_call_as_method(class_name, object, sub_call);
    }
    //Parse for variable
    else
    {
        //Gets variable information from symbol table
        st_variable temp = lookup_variable(name);
        string segment = temp.segment;
        int offset = temp.offset;
        string type = temp.type;

        pop_error_context() ;
        return create_var(name, segment, offset, type);
    }

    pop_error_context() ;
    return -1 ;
}

// index ::= '[' expr ']'
// returns ast_expr
//Parses an index expression
ast parse_index()
{
    push_error_context("parse_index()") ;

    //Checks index syntax
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
//Parses an ID Call
ast parse_id_call()
{
    push_error_context("parse_id_call()") ;

    //Gets the method name and call ast
    mustbe(tk_stop);
    string name = token_spelling( mustbe(tk_identifier) );
    ast call = parse_call();

    pop_error_context() ;
    return create_subr_call(name, call) ;
}

// call ::= '(' expr_list ')'
// returns ast_expr_list
//
//Parses a call
ast parse_call()
{
    push_error_context("parse_call()") ;

    //Checks for call syntax as outlined
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
//Parses the expression list
ast parse_expr_list()
{
    push_error_context("parse_expr_list()") ;

    vector<ast> expression_list;

    //Check for the start of an expression and pushes to vector
    if ( have( current_token(), tk_term) )
    {
        expression_list.push_back( parse_expr() );

        //While additional expressions, push to vector
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
//Parses Infix Operators
ast parse_infix_op()
{
    push_error_context("parse_infix_op()") ;

    //Gets the spelling of the operator
    Token infix_oper = mustbe(tk_infix_op);
    string op = token_spelling(infix_oper);

    pop_error_context() ;
    return create_infix_op(op) ;
}

// unary_op ::= '-' | '~'
// returns Token for the unary_op
//
//Parses Unary Operators
Token parse_unary_op()
{
    push_error_context("parse_unary_op()") ;

    //Gets the spelling of the operator
    Token unary_oper = mustbe(tk_unary_op);

    pop_error_context() ;
    return unary_oper ;
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
