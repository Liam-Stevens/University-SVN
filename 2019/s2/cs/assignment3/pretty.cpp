#include "iobuffer.h"
#include "symbols.h"
#include "abstract-syntax-tree.h"

// to shorten our code:
using namespace std ;
using namespace CS_IO_Buffers ;
using namespace Jack_Compiler ;

// ***** WHAT TO DO *****
//
// MODIFY the skeleton code below to walk an abstract syntax tree, ast, of a Jack class
//        and pretty print the equivalent Jack source code.
//
// The skeleton code has one function per node in the abstract tree
//  - they each extract all fields into local variables
//  - they each call the appropriate walk_* function to walk any sub-trees
//
// The structure of the skeleton code is just a suggestion
//  - you may want to change the parameters / results to suit your own logic
//  - you can change it as much as you like

// forward declarations of one function per node in the abstract syntax tree
void walk_class(ast t) ;
void walk_class_var_decs(ast t) ;
void walk_var_dec(ast t, bool param) ;
void walk_subr_decs(ast t) ;
void walk_subr(ast t) ;
void walk_constructor(ast t) ;
void walk_function(ast t) ;
void walk_method(ast t) ;
void walk_param_list(ast t) ;
void walk_subr_body(ast t) ;
void walk_var_decs(ast t) ;
void walk_statements(ast t) ;
void walk_statement(ast t) ;
void walk_let(ast t) ;
void walk_let_array(ast t) ;
void walk_if(ast t) ;
void walk_if_else(ast t) ;
void walk_while(ast t) ;
void walk_do(ast t) ;
void walk_return(ast t) ;
void walk_return_expr(ast t) ;
void walk_expr(ast t) ;
void walk_term(ast t) ;
void walk_int(ast t) ;
void walk_string(ast t) ;
void walk_bool(ast t) ;
void walk_null(ast t) ;
void walk_this(ast t) ;
void walk_unary_op(ast t) ;
void walk_var(ast t) ;
void walk_array_index(ast t) ;
void walk_call_as_function(ast t) ;
void walk_call_as_method(ast t) ;
void walk_subr_call(ast t) ;
void walk_expr_list(ast t) ;
void walk_infix_op(ast t) ;

//String of spaces to append to the front
string indents;
//For checking if a new line is needed in var_decs
bool new_line_statement;

//Increases or decreases the indentation level
void indent(string op)
{
    if (op == "add")
    {
        indents += "    ";
    }
    else if (op == "sub")
    {
        indents.erase(indents.end()-4,indents.end());
    }
}

//Walks over a class
void walk_class(ast t)
{
    string myclassname = get_class_class_name(t) ;
    ast var_decs = get_class_var_decs(t) ;
    ast subr_decs = get_class_subr_decs(t) ;

    //Initialising variables
    indents = "";
    new_line_statement = false;

    write_to_output(indents+"class "+myclassname+"\n");
    write_to_output(indents+"{\n");
    indent("add");

    walk_class_var_decs(var_decs) ;
    walk_subr_decs(subr_decs) ;

    indent("sub");
    write_to_output(indents+"}\n");
}

//Walks over the class variable declarations
void walk_class_var_decs(ast t)
{
    int ndecs = size_of_class_var_decs(t) ;
    for ( int i = 0 ; i < ndecs ; i++ )
    {
        walk_var_dec(get_class_var_decs(t,i), false) ;
    }

    //New line if there were variables
    if (ndecs > 0)
    {
        write_to_output("\n");
    }
}

//Walks over variable declarations
void walk_var_dec(ast t, bool param)
{
    string name = get_var_dec_name(t) ;
    string type = get_var_dec_type(t) ;
    string segment = get_var_dec_segment(t) ;
    int offset = get_var_dec_offset(t) ;

    string var_type;
    string tmp_indent = indents;
    string tmp_end = " ;\n";

    //Fixes the name for the variable declaration
    if (segment == "local")
    {
        var_type = "var ";
    }
    else if (segment == "this")
    {
        var_type = "field ";
    }
    else
    {
        var_type = segment + " ";
    }

    //Suppresses output if called from param_list
    if (param == true)
    {
        var_type = "";
        tmp_indent = "";
        tmp_end = "";
    }

    write_to_output(tmp_indent+var_type+type+" "+name+tmp_end);
}

//Walks over the subroutine declarations
void walk_subr_decs(ast t)
{
    int size = size_of_subr_decs(t) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        walk_subr(get_subr_decs(t,i)) ;

        //New line for all but the last
        if (i < size-1)
        {
            write_to_output("\n");
        }
    }
}

//Walks over subroutines
void walk_subr(ast t)
{
    ast subr = get_subr_subr(t) ;

    switch(ast_node_kind(subr))
    {
    case ast_constructor:
        walk_constructor(subr) ;
        break ;
    case ast_function:
        walk_function(subr) ;
        break ;
    case ast_method:
        walk_method(subr) ;
        break ;
    default:
        fatal_error(0,"Unexpected subroutine kind") ;
        break ;
    }
}

//Walks over a constructor
void walk_constructor(ast t)
{
    string vtype = get_constructor_vtype(t) ;
    string name = get_constructor_name(t) ;
    ast param_list = get_constructor_param_list(t) ;
    ast subr_body = get_constructor_subr_body(t) ;

    write_to_output(indents+"constructor "+vtype+" "+name+"(");
    walk_param_list(param_list) ;
    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_subr_body(subr_body) ;

    indent("sub");
    write_to_output(indents+"}\n");
}

//Walks over a function
void walk_function(ast t)
{
    string vtype = get_function_vtype(t) ;
    string name = get_function_name(t) ;
    ast param_list = get_function_param_list(t) ;
    ast subr_body = get_function_subr_body(t) ;

    write_to_output(indents+"function "+vtype+" "+name+"(");
    walk_param_list(param_list) ;
    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_subr_body(subr_body) ;

    indent("sub");
    write_to_output(indents+"}\n");

}

//Walks over a method
void walk_method(ast t)
{
    string vtype = get_method_vtype(t) ;
    string name = get_method_name(t) ;
    ast param_list = get_method_param_list(t) ;
    ast subr_body = get_method_subr_body(t) ;

    write_to_output(indents+"method "+vtype+" "+name+"(");
    walk_param_list(param_list) ;
    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_subr_body(subr_body) ;

    indent("sub");
    write_to_output(indents+"}\n");
}

//Walks over the parameter list
void walk_param_list(ast t)
{
    int ndecs = size_of_param_list(t) ;

    for ( int i = 0 ; i < ndecs ; i++ )
    {
        //Places a comma between parameters
        if (i != 0)
        {
            write_to_output(",");
        }
        walk_var_dec(get_param_list(t,i), true) ;
    }

}

//Walks over a subroutine body
void walk_subr_body(ast t)
{
    ast decs = get_subr_body_decs(t) ;
    ast body = get_subr_body_body(t) ;

    walk_var_decs(decs) ;
    walk_statements(body) ;
}

//Walks over variable declarations
void walk_var_decs(ast t)
{
    int ndecs = size_of_var_decs(t) ;
    for ( int i = 0 ; i < ndecs ; i++ )
    {
        walk_var_dec(get_var_decs(t,i), false) ;
    }

    //Places a new line if there were variables declared
    if (ndecs > 0)
    {
        write_to_output("\n");
    }
}

//Walks over statements
void walk_statements(ast t)
{
    int nstatements = size_of_statements(t) ;
    for ( int i = 0 ; i < nstatements ; i++ )
    {
        walk_statement(get_statements(t,i)) ;

        //Places a new line for if and while, if it is not the last statement
        if (i < nstatements-1 && new_line_statement == true)
        {
            write_to_output("\n");
            new_line_statement = false;
        }
    }
}

//Walks over a statement
void walk_statement(ast t)
{
    ast statement = get_statement_statement(t) ;

    switch(ast_node_kind(statement))
    {
    case ast_let:
        walk_let(statement) ;
        break ;
    case ast_let_array:
        walk_let_array(statement) ;
        break ;
    case ast_if:
        walk_if(statement) ;
        break ;
    case ast_if_else:
        walk_if_else(statement) ;
        break ;
    case ast_while:
        walk_while(statement) ;
        break ;
    case ast_do:
        walk_do(statement) ;
        break ;
    case ast_return:
        walk_return(statement) ;
        break ;
    case ast_return_expr:
        walk_return_expr(statement) ;
        break ;
    case ast_statements:
        walk_statements(statement) ;
        break ;
    default:
        fatal_error(0,"Unexpected statement kind") ;
        break ;
    }
}

//Walks over a let statement
void walk_let(ast t)
{
    ast var = get_let_var(t) ;
    ast expr = get_let_expr(t) ;

    write_to_output(indents+"let ");

    walk_var(var) ;

    write_to_output(" = ");

    walk_expr(expr) ;

    write_to_output(" ;\n");
}

//Walks over a let-array statement
void walk_let_array(ast t)
{
    ast var = get_let_array_var(t) ;
    ast index = get_let_array_index(t) ;
    ast expr = get_let_array_expr(t) ;

    write_to_output(indents+"let ");

    walk_var(var) ;

    write_to_output("[");
    walk_expr(index) ;
    write_to_output("]");

    write_to_output(" = ");

    walk_expr(expr) ;

    write_to_output(" ;\n");
}

//Walks over an if statement
void walk_if(ast t)
{
    ast condition = get_if_condition(t) ;
    ast if_true = get_if_if_true(t) ;

    write_to_output(indents+"if (");
    walk_expr(condition) ;
    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_statements(if_true) ;

    indent("sub");
    write_to_output(indents+"}\n");
    //Places conditional new line
    new_line_statement = true;
}

//Walks over an if-else statement
void walk_if_else(ast t)
{
    ast condition = get_if_else_condition(t) ;
    ast if_true = get_if_else_if_true(t) ;
    ast if_false = get_if_else_if_false(t) ;

    write_to_output(indents+"if (");
    walk_expr(condition) ;
    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_statements(if_true) ;

    indent("sub");
    write_to_output(indents+"}\n");
    write_to_output(indents+"else\n"+indents+"{\n");
    indent("add");

    walk_statements(if_false) ;

    indent("sub");
    write_to_output(indents+"}\n");
    //Places conditional new line
    new_line_statement = true;
}

//Walks over a while statement
void walk_while(ast t)
{
    ast condition = get_while_condition(t) ;
    ast body = get_while_body(t) ;

    write_to_output(indents+"while (");

    walk_expr(condition) ;

    write_to_output(")\n"+indents+"{\n");
    indent("add");

    walk_statements(body) ;

    indent("sub");
    write_to_output(indents+"}\n");
    //Places conditional new line
    new_line_statement = true;
}

//Walks over a do statement
void walk_do(ast t)
{
    ast call = get_do_call(t) ;

    write_to_output(indents+"do ");

    switch(ast_node_kind(call))
    {
    case ast_call_as_function:
        walk_call_as_function(call) ;
        break ;
    case ast_call_as_method:
        walk_call_as_method(call) ;
        break ;
    default:
        fatal_error(0,"Unexpected call kind") ;
        break ;
    }

    write_to_output(" ;\n");
}

//Walks over a return statement
void walk_return(ast t)
{
    write_to_output(indents+"return ;\n");
}

//Walks over a return expression statement
void walk_return_expr(ast t)
{
    ast expr = get_return_expr(t) ;

    write_to_output(indents+"return ");
    walk_expr(expr) ;
    write_to_output(" ;\n");
}

//Walks over an expression
void walk_expr(ast t)
{
    int term_ops = size_of_expr(t) ;
    for ( int i = 0 ; i < term_ops ; i++ )
    {
        ast term_op = get_expr(t,i) ;
        if ( i % 2 == 0 )
        {
            walk_term(term_op) ;
        }
        else
        {
            walk_infix_op(term_op) ;
        }
    }
}

//Walks over a term
void walk_term(ast t)
{
    ast term = get_term_term(t) ;

    switch(ast_node_kind(term))
    {
    case ast_int:
        walk_int(term) ;
        break ;
    case ast_string:
        walk_string(term) ;
        break ;
    case ast_bool:
        walk_bool(term) ;
        break ;
    case ast_null:
        walk_null(term) ;
        break ;
    case ast_this:
        walk_this(term) ;
        break ;
    case ast_expr:
        walk_expr(term) ;
        break ;
    case ast_unary_op:
        walk_unary_op(term) ;
        break ;
    case ast_var:
        walk_var(term) ;
        break ;
    case ast_array_index:
        walk_array_index(term) ;
        break ;
    case ast_call_as_function:
        walk_call_as_function(term) ;
        break ;
    case ast_call_as_method:
        walk_call_as_method(term) ;
        break ;
    default:
        fatal_error(0,"Unexpected term kind") ;
        break ;
    }
}

//Walks over an integer
void walk_int(ast t)
{
    int _constant = get_int_constant(t) ;
    write_to_output(to_string(_constant));
}

//Walks over a string
void walk_string(ast t)
{
    string _constant = get_string_constant(t) ;
    write_to_output("\""+_constant+"\"");
}

//Walks over a boolean
void walk_bool(ast t)
{
    bool _constant = get_bool_t_or_f(t) ;

    if (_constant)
    {
        write_to_output("true");
    }
    else
    {
        write_to_output("false");
    }
}

//Walks over null
void walk_null(ast t)
{
    write_to_output("null");
}

//Walks over this
void walk_this(ast t)
{
    write_to_output("this");
}

//Walks over an unary operator
void walk_unary_op(ast t)
{
    string uop = get_unary_op_op(t);
    ast term = get_unary_op_term(t) ;

    write_to_output(uop);
    walk_term(term) ;
}

//Walks over a variable
void walk_var(ast t)
{
    string name = get_var_name(t) ;
    string type = get_var_type(t) ;
    string segment = get_var_segment(t) ;
    int offset = get_var_offset(t) ;

    write_to_output(name);
}

//Walks over an array index
void walk_array_index(ast t)
{
    ast var = get_array_index_var(t) ;
    ast index = get_array_index_index(t) ;

    walk_var(var) ;

    write_to_output("[");
    walk_expr(index) ;
    write_to_output("]");
}

//Walks over a call as function
void walk_call_as_function(ast t)
{
    string class_name = get_call_as_function_class_name(t) ;
    ast subr_call = get_call_as_function_subr_call(t) ;

    write_to_output(class_name+".");

    walk_subr_call(subr_call) ;
}

//Walks over a call as method
void walk_call_as_method(ast t)
{
    string class_name = get_call_as_method_class_name(t) ;
    ast var = get_call_as_method_var(t) ;
    ast subr_call = get_call_as_method_subr_call(t) ;

    switch(ast_node_kind(var))
    {
    case ast_this:
        walk_this(var) ;
        break ;
    case ast_var:
        walk_var(var) ;
        break ;
    default:
        fatal_error(0,"Expected var or this") ;
        break ;
    }

    write_to_output(".");

    walk_subr_call(subr_call) ;
}

//Walks over a subroutine call
void walk_subr_call(ast t)
{
    string subr_name = get_subr_call_subr_name(t) ;
    ast expr_list = get_subr_call_expr_list(t) ;

    write_to_output(subr_name);

    walk_expr_list(expr_list) ;
}

//Walks over an expression list
void walk_expr_list(ast t)
{
    int nexpressions = size_of_expr_list(t) ;

    write_to_output("(");
    for ( int i = 0 ; i < nexpressions ; i++ )
    {
        //Places a comma between expressions
        if (i != 0)
        {
            write_to_output(",");
        }
        walk_expr(get_expr_list(t,i)) ;
    }
    write_to_output(")");
}

//Walks over an infix operator
void walk_infix_op(ast t)
{
    string op = get_infix_op_op(t) ;

    write_to_output(" "+op+" ");
}

// main program
int main(int argc,char **argv)
{
    // walk an AST parsed from XML and pretty print equivalent Jack code
    walk_class(ast_parse_xml()) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}
