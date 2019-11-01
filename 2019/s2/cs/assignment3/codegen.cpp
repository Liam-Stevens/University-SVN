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
//        and generate the equivalent Hack Virtual Machine Code.
//
// NOTE: the correct segment and offset is recorded with every variable in the ast
//       so the code generator does not need to use any symbol tables
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
void walk_var_dec(ast t) ;
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

//Tracks the name of the current class
string current_class;
//Track the number of times a function or variable has been declared
int while_counter;
int if_counter;
int field_counter;

//Resets the counters which should be reset for each scope
void reset_counters()
{
    while_counter = 0;
    if_counter = 0;
}

//Walks over class declaration
void walk_class(ast t)
{
    string myclassname = get_class_class_name(t) ;
    ast var_decs = get_class_var_decs(t) ;
    ast subr_decs = get_class_subr_decs(t) ;
    current_class = myclassname;

    reset_counters();

    walk_class_var_decs(var_decs) ;
    walk_subr_decs(subr_decs) ;
}

//Walks over the class variable declarations
void walk_class_var_decs(ast t)
{
    int ndecs = size_of_class_var_decs(t) ;
    for ( int i = 0 ; i < ndecs ; i++ )
    {
        walk_var_dec(get_class_var_decs(t,i)) ;
    }
}

//Walks over variable declarations
void walk_var_dec(ast t)
{
    string name = get_var_dec_name(t) ;
    string type = get_var_dec_type(t) ;
    string segment = get_var_dec_segment(t) ;
    int offset = get_var_dec_offset(t) ;

    //Counts the number of field variables
    if (segment == "this")
    {
        field_counter++;
    }
}

//Walks over the subroutine declarations
void walk_subr_decs(ast t)
{
    int size = size_of_subr_decs(t) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        walk_subr(get_subr_decs(t,i)) ;
    }
}

//Walks over subroutines
void walk_subr(ast t)
{
    ast subr = get_subr_subr(t) ;

    reset_counters();
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

    //Get the number of variables
    int num_of_vars = size_of_var_decs( get_subr_body_decs(subr_body) );

    write_to_output("function " + current_class + "." + name + " " + to_string( num_of_vars ) + "\n");
    write_to_output("push constant "+to_string(field_counter)+"\n");
    write_to_output("call Memory.alloc 1\n");
    write_to_output("pop pointer 0\n");

    walk_param_list(param_list) ;

    walk_subr_body(subr_body) ;


}

//Walks over a function
void walk_function(ast t)
{
    string vtype = get_function_vtype(t) ;
    string name = get_function_name(t) ;
    ast param_list = get_function_param_list(t) ;
    ast subr_body = get_function_subr_body(t) ;

    //Get the number of variables
    int num_of_vars = size_of_var_decs( get_subr_body_decs(subr_body) );

    write_to_output("function " + current_class + "." + name + " " + to_string( num_of_vars ) + "\n");

    walk_param_list(param_list) ;
    walk_subr_body(subr_body) ;
}

//Walks over a method
void walk_method(ast t)
{
    string vtype = get_method_vtype(t) ;
    string name = get_method_name(t) ;
    ast param_list = get_method_param_list(t) ;
    ast subr_body = get_method_subr_body(t) ;

    //Get the number of variables
    int num_of_vars = size_of_var_decs( get_subr_body_decs(subr_body) );

    write_to_output("function " + current_class + "." + name + " " + to_string( num_of_vars ) + "\n");
    write_to_output("push argument 0\n");
    write_to_output("pop pointer 0\n");

    walk_param_list(param_list) ;
    walk_subr_body(subr_body) ;
}

//Walks over the parameter list
void walk_param_list(ast t)
{
    int ndecs = size_of_param_list(t) ;
    for ( int i = 0 ; i < ndecs ; i++ )
    {
        walk_var_dec(get_param_list(t,i)) ;
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
        walk_var_dec(get_var_decs(t,i)) ;
    }
}

//Walks over statements
void walk_statements(ast t)
{
    int nstatements = size_of_statements(t) ;
    for ( int i = 0 ; i < nstatements ; i++ )
    {
        walk_statement(get_statements(t,i)) ;
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

    walk_expr(expr) ;

    write_to_output("pop "+get_var_segment(var)+" "+to_string(get_var_offset(var))+"\n");
}

//Walks over a let-array statement
void walk_let_array(ast t)
{
    ast var = get_let_array_var(t) ;
    ast index = get_let_array_index(t) ;
    ast expr = get_let_array_expr(t) ;

    //Needs work

    walk_var(var) ;
    walk_expr(index) ;
    walk_expr(expr) ;
}

//Walks over an if statement
void walk_if(ast t)
{
    ast condition = get_if_condition(t) ;
    ast if_true = get_if_if_true(t) ;

    //Grabs the counter and increments it incase a if-statement is in the body
    int index = if_counter;
    if_counter++;

    walk_expr(condition) ;

    write_to_output("if-goto IF_TRUE"+to_string(index)+"\n");
    write_to_output("goto IF_FALSE"+to_string(index)+"\n");
    write_to_output("label IF_TRUE"+to_string(index)+"\n");

    walk_statements(if_true) ;

    write_to_output("label IF_FALSE"+to_string(index)+"\n");
}

//Walks over an if-else statement
void walk_if_else(ast t)
{
    ast condition = get_if_else_condition(t) ;
    ast if_true = get_if_else_if_true(t) ;
    ast if_false = get_if_else_if_false(t) ;

    //Grabs the counter and increments it incase a if-statement is in the body
    int index = if_counter;
    if_counter++;

    walk_expr(condition) ;

    write_to_output("if-goto IF_TRUE"+to_string(index)+"\n");
    write_to_output("goto IF_FALSE"+to_string(index)+"\n");
    write_to_output("label IF_TRUE"+to_string(index)+"\n");

    walk_statements(if_true) ;

    write_to_output("goto IF_END"+to_string(index)+"\n");
    write_to_output("label IF_FALSE"+to_string(index)+"\n");

    walk_statements(if_false) ;

    write_to_output("label IF_END"+to_string(index)+"\n");
}

//Walks over a while statement
void walk_while(ast t)
{
    ast condition = get_while_condition(t) ;
    ast body = get_while_body(t) ;

    //Grabs the counter and increments it incase a while-statement is in the body
    int index = while_counter;
    while_counter++;

    write_to_output("label WHILE_EXP"+to_string(index)+"\n");

    walk_expr(condition) ;

    write_to_output("not\n");
    write_to_output("if-goto WHILE_END"+to_string(index)+"\n");

    walk_statements(body) ;

    write_to_output("goto WHILE_EXP"+to_string(index)+"\n");

    write_to_output("label WHILE_END"+to_string(index)+"\n");

}

//Walks over a do statement
void walk_do(ast t)
{
    ast call = get_do_call(t) ;

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

    write_to_output("pop temp 0\n");
}

//Walks over a return statement
void walk_return(ast t)
{
    write_to_output("push constant 0\n");
    write_to_output("return\n");
}

//Walks over a return expression statement
void walk_return_expr(ast t)
{
    ast expr = get_return_expr(t) ;

    walk_expr(expr) ;

    write_to_output("return\n");
}

//Walks over an expression
void walk_expr(ast t)
{
    int term_ops = size_of_expr(t) ;
    //Loop increments in 2s to get each term
    for ( int i = 0 ; i < term_ops ; i += 2 )
    {
        ast term_op = get_expr(t,i) ;
        if ( i % 2 == 0 )
        {
            walk_term(term_op) ;
            //Effectivly reduces the index by 1 when its not on the first term, such that it sees the operator
            if ( i != 0 )
            {
                i -= 3;
            }
        }
        else
        {
            walk_infix_op(term_op) ;
            //Skips the following term, as it has already been pushed
            i++;
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
    write_to_output("push constant "+to_string(_constant)+"\n");
}

//Walks over a string
void walk_string(ast t)
{
    string _constant = get_string_constant(t) ;

    write_to_output("push constant "+to_string(_constant.length())+"\n");
    write_to_output("call String.new 1\n");
    //Appends the index location of the character in the string
    for (int i = 0; i < _constant.length(); i++)
    {
        write_to_output("push constant "+to_string((int)_constant[i])+"\n");
        write_to_output("call String.appendChar 2\n");
    }
}

//Walks over a boolean
void walk_bool(ast t)
{
    bool _constant = get_bool_t_or_f(t) ;
    write_to_output("push constant 0\n");

    if (_constant)
    {
        write_to_output("not\n");
    }
}

//Walks over null
void walk_null(ast t)
{
    write_to_output("push constant 0\n");
}

//Walks over this
void walk_this(ast t)
{
    write_to_output("push pointer 0\n");
}

//Walks over an unary operator
void walk_unary_op(ast t)
{
    string uop = get_unary_op_op(t);
    ast term = get_unary_op_term(t) ;

    walk_term(term) ;

    if (uop == "~")
    {
        write_to_output("not\n");
    } else if (uop == "-")
    {
        write_to_output("neg\n");
    }

}

//Walks over a variable
void walk_var(ast t)
{
    string name = get_var_name(t) ;
    string type = get_var_type(t) ;
    string segment = get_var_segment(t) ;
    int offset = get_var_offset(t) ;

    write_to_output("push "+segment+" "+to_string(offset)+"\n");
}

//Walks over an array index
void walk_array_index(ast t)
{
    ast var = get_array_index_var(t) ;
    ast index = get_array_index_index(t) ;

    walk_var(var) ;
    walk_expr(index) ;
}

//Walks over a call as function
void walk_call_as_function(ast t)
{
    string class_name = get_call_as_function_class_name(t) ;
    ast subr_call = get_call_as_function_subr_call(t) ;

    walk_subr_call(subr_call) ;

    string call_name = get_subr_call_subr_name(subr_call);
    ast expr_list = get_subr_call_expr_list(subr_call);
    int vars = size_of_expr_list(expr_list);

    write_to_output("call "+class_name+"."+call_name+" "+to_string(vars)+"\n");
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
    walk_subr_call(subr_call) ;

    string call_name = get_subr_call_subr_name(subr_call);
    ast expr_list = get_subr_call_expr_list(subr_call);
    int vars = size_of_expr_list(expr_list) + 1;

    write_to_output("call "+class_name+"."+call_name+" "+to_string(vars)+"\n");
}

//Walks over a subroutine call
void walk_subr_call(ast t)
{
    string subr_name = get_subr_call_subr_name(t) ;
    ast expr_list = get_subr_call_expr_list(t) ;

    walk_expr_list(expr_list) ;
}

//Walks over an expression list
void walk_expr_list(ast t)
{
    int nexpressions = size_of_expr_list(t) ;
    for ( int i = 0 ; i < nexpressions ; i++ )
    {
        walk_expr(get_expr_list(t,i)) ;
    }
}

//Walks over an infix operator
void walk_infix_op(ast t)
{
    string op = get_infix_op_op(t) ;
    if (op == "+")
    {
        write_to_output("add\n");
    } else if (op == "-")
    {
        write_to_output("sub\n");
    } else if (op == "*")
    {
        write_to_output("call Math.multiply 2\n");
    } else if (op == "/")
    {
        write_to_output("call Math.divide 2\n");
    } else if (op == "&")
    {
        write_to_output("and\n");
    } else if (op == "|")
    {
        write_to_output("or\n");
    } else if (op == "<")
    {
        write_to_output("lt\n");
    } else if (op == ">")
    {
        write_to_output("gt\n");
    } else if (op == "=")
    {
        write_to_output("eq\n");
    }
}

// main program
int main(int argc,char **argv)
{
    // walk an AST parsed from XML and print VM code
    walk_class(ast_parse_xml()) ;

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}
