// convert a document tree into VM code
#include "iobuffer.h"
#include "abstract-syntax-tree.h"
#include "assembler-internal.h"

// to make out programs a bit neater
using namespace std ;

using namespace CS_IO_Buffers ;
using namespace Hack_Virtual_Machine ;

// grammer to be parsed:
// vm_class ::= command* eoi
// command ::= vm_operator | vm_jump | vm_func | vm_stack
// vm_operator ::= 'add' | 'and' | 'eq' | 'gt' | 'lt' | 'neg' | 'not' | 'or' | 'sub' | 'return'
// vm_jump ::= jump label
// vm_func ::= func label number
// vm_stack ::= stack segment number

// forward declare parsing functions - one per rule
static void translate_vm_class(ast root) ;
static void translate_vm_command(ast command) ;
static void translate_vm_operator(ast vm_op) ;
static void translate_vm_jump(ast jump) ;
static void translate_vm_func(ast func) ;
static void translate_vm_stack(ast stack) ;



////////////////////////////////////////////////////////////////

/************   PUT YOUR HELPER FUNCTIONS HERE   **************/
int gtCalls;
int ltCalls;
int eqCalls;

static void set_numbers()
{
    gtCalls = 0;
    ltCalls = 0;
    eqCalls = 0;
}

//Pushes a constant to the stack
static void push_zero()
{
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=0");
}

static void temp_function()
{

}


/************      END OF HELPER FUNCTIONS       **************/

///////////////////////////////////////////////////////////////



// the function translate_vm_class() will be called by the main program
// its is passed the abstract syntax tree constructed by the parser
// it walks the abstract syntax tree and produces the equivalent VM code as output
static void translate_vm_class(ast root)
{
    // assumes we have a "class" node containing VM command nodes
    ast_mustbe_kind(root,ast_vm_class) ;

    // tell the output system we are starting to translate VM commands for a Jack class
    start_of_vm_class() ;

    int ncommands = size_of_vm_class(root) ;
    for ( int i = 0 ; i < ncommands ; i++ )
    {
        translate_vm_command(get_vm_class(root,i)) ;
    }

    // tell the output system we have just finished translating VM commands for a Jack class
    end_of_vm_class() ;

}

// translate the current vm command - a bad node is a fatal error
static void translate_vm_command(ast command)
{
    switch(ast_node_kind(command))
    {
    case ast_vm_operator:
        translate_vm_operator(command) ;
        break ;
    case ast_vm_jump:
        translate_vm_jump(command) ;
        break ;
    case ast_vm_function:
        translate_vm_func(command) ;
        break ;
    case ast_vm_stack:
        translate_vm_stack(command) ;
        break ;
    default:
        fatal_error(0,"// bad node - expected vm_operator, vm_jump, vm_function or vm_stack\n") ;
        break ;
    }
}

// translate vm operator command into assembly language
static void translate_vm_operator(ast vm_op)
{
    // extract command specific info from the ast node passed in
    string the_op = get_vm_operator_command(vm_op) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_operator_command(the_op) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...

    if (the_op == "add")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D+M");
    }

    if (the_op == "and")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D&M");
    }

    if (the_op == "eq")
    {
        int tmp = eqCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@Coverage.ff5$EQ_"+to_string(tmp));
        output_assembler("D;JNE");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@Coverage.ff5$EQ_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("(Coverage.ff5$EQ_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("(Coverage.ff5$EQ_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        eqCalls = eqCalls + 2;
    }

    if (the_op == "gt")
    {
        int tmp = gtCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@Coverage.main$GT_"+to_string(tmp));
        output_assembler("D;JLT");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@Coverage.main$GT_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("(Coverage.main$GT_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("(Coverage.main$GT_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        gtCalls = gtCalls + 2;
    }

    if (the_op == "lt")
    {
        int tmp = ltCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@Coverage.main$LT_"+to_string(tmp));
        output_assembler("D;JGT");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@Coverage.main$LT_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("(Coverage.main$LT_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("(Coverage.main$LT_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        ltCalls = ltCalls + 2;
    }

    if (the_op == "neg")
    {
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D-M");
    }

    if (the_op == "not")
    {
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=!M");
    }

    if (the_op == "or")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D|M");
    }

    if (the_op == "sub")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=M-D");

    }

    if (the_op == "return")
    {

    }




    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_jump(ast jump)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_jump_command(jump) ;
    string label = get_vm_jump_label(jump) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_jump_command(command,label) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...

    //output_assembler("// "+command+" "+label);
    if (command == "label")
    {
        output_assembler("(Coverage.main$"+label+")");
    }

    if (command == "goto")
    {
        output_assembler("@Coverage.main$"+label);
        output_assembler("0;JMP");
    }

    if (command == "if-goto")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("@Coverage.main$"+label);
        output_assembler("D;JNE");
    }


    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_func(ast func)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_function_command(func) ;
    string label = get_vm_function_label(func) ;
    int number = get_vm_function_number(func) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_func_command(command,label,number) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...

    //output_assembler("// "+command+" "+label+" "+to_string(number));
    if ( command == "function" )
    {
        output_assembler("("+label+")");
        for (int i = 0; i < number; i++)
        {
            push_zero();
        }
    }

    if (command == "call")
    {

    }

    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_stack(ast stack)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_stack_command(stack) ;
    string segment = get_vm_stack_segment(stack) ;
    int number = get_vm_stack_offset(stack) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_stack_command(command,segment,number) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...

    output_assembler("// "+command+" "+segment+" "+to_string(number));
    if (command == "push")
    {
        if (segment == "constant")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@SP");
            output_assembler("AM=M+1");
            output_assembler("A=A-1");
            output_assembler("M=D");
        }
        if (segment == "static")
        {
            output_assembler("@"+to_string(16+number));
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("AM=M+1");
            output_assembler("A=A-1");
            output_assembler("M=D");
        }

        if (segment == "local")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@LCL");
            output_assembler("A=D+M");
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("AM=M+1");
            output_assembler("A=A-1");
            output_assembler("M=D");
        }

        if (segment == "argument")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@ARG");
            output_assembler("A=D+M");
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("AM=M+1");
            output_assembler("A=A-1");
            output_assembler("M=D");
        }

    }

    if (command == "pop")
    {
        if (segment == "pointer")
        {
            output_assembler("@SP");
            output_assembler("AM=M-1");
            output_assembler("D=M");
            output_assembler("@"+to_string(3+number));
            output_assembler("M=D");
        }

        if (segment == "local")
        {

        }

        if (segment == "argument")
        {

        }

        if (segment == "temp")
        {

        }

    }

    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// main program
int main(int argc,char **argv)
{
    set_numbers();

    // parse abstract syntax tree and pass to the translator
    translate_vm_class(ast_parse_xml()) ;

    // flush output and errors
    print_output() ;
    print_errors() ;
}
