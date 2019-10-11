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
// These are trackers to make labels different
int gtCalls;
int ltCalls;
int eqCalls;
int callCalls;
string className;

//Ensures labels start at zero
static void set_numbers()
{
    gtCalls = 0;
    ltCalls = 0;
    eqCalls = 0;
    callCalls = 0;
}

//Pushes zero to the stack
static void push_zero()
{
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=0");
}

//Pushes D to the stack
static void do_push()
{
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");
}

//Pops the top of the stack into D
static void do_pop()
{
    output_assembler("@SP");
    output_assembler("AM=M-1");
    output_assembler("D=M");
}

//Easy push function - this code breaks lt when used???
static void push_into(string location, int stack)
{
    output_assembler("@"+to_string(stack));
    output_assembler("D=A");
    output_assembler(location);
    output_assembler("A=D+M");
    output_assembler("D=M");
    do_push();
}

//Easy pop function
static void pop_into(string location, int offset)
{
    do_pop();
    output_assembler(location);
    output_assembler("A=M");
    for (int i = 0; i < offset; i++)
    {
        output_assembler("A=A+1");
    }
    output_assembler("M=D");
}

//Used for moving the where I am looking the on stack back easily
static void move_back(int number)
{
    for (int i = 0; i < number; i++)
    {
        output_assembler("A=A-1");
    }
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

    //Add operator
    if (the_op == "add")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D+M");
    }

    //And operator
    if (the_op == "and")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D&M");
    }

    //Equals operator
    if (the_op == "eq")
    {
        int tmp = eqCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@"+className+"$EQ_"+to_string(tmp));
        output_assembler("D;JNE");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@"+className+"$EQ_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("("+className+"$EQ_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("("+className+"$EQ_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        eqCalls = eqCalls + 2;
    }

    //Greater Than operator
    if (the_op == "gt")
    {
        int tmp = gtCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@"+className+"$GT_"+to_string(tmp));
        output_assembler("D;JLT");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@"+className+"$GT_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("("+className+"$GT_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("("+className+"$GT_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        gtCalls = gtCalls + 2;
    }

    //Less Than Operator
    if (the_op == "lt")
    {
        int tmp = ltCalls;
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("@"+className+"$LT_"+to_string(tmp));
        output_assembler("D;JGT");
        output_assembler("@1");
        output_assembler("D=A");
        output_assembler("D=D-A");
        output_assembler("D=D-A");
        output_assembler("@"+className+"$LT_"+to_string(tmp+1));
        output_assembler("0;JMP");
        output_assembler("("+className+"$LT_"+to_string(tmp)+")");
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("("+className+"$LT_"+to_string(tmp+1)+")");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D");
        ltCalls = ltCalls + 2;
    }

    //Negate Operator
    if (the_op == "neg")
    {
        output_assembler("@0");
        output_assembler("D=A");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=D-M");
    }

    //Not Operator
    if (the_op == "not")
    {
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=!M");
    }

    //Or Operator
    if (the_op == "or")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=D|M");
    }

    //Subtraction Operator
    if (the_op == "sub")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=M-D");

    }

    //Return function
    if (the_op == "return")
    {
        //frame = LCL
        output_assembler("@LCL");
        output_assembler("D=M");
        output_assembler("@13");
        output_assembler("M=D");
        //retAddr = frame-5
        output_assembler("@LCL");
        output_assembler("A=M");
        move_back(5);
        output_assembler("D=M");
        output_assembler("@14");
        output_assembler("M=D");
        //ARG = pop
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("D=M");
        output_assembler("@ARG");
        output_assembler("A=M");
        output_assembler("M=D");
        //SP = ARG+1
        output_assembler("D=A");
        output_assembler("@SP");
        output_assembler("M=D+1");
        //THAT = frame-1
        output_assembler("@13");
        output_assembler("A=M-1");
        output_assembler("D=M");
        output_assembler("@THAT");
        output_assembler("M=D");
        //THIS = frame-2
        output_assembler("@13");
        output_assembler("A=M-1");
        output_assembler("A=A-1");
        output_assembler("D=M");
        output_assembler("@THIS");
        output_assembler("M=D");
        //ARG = frame-3
        output_assembler("@13");
        output_assembler("A=M-1");
        move_back(2);
        output_assembler("D=M");
        output_assembler("@ARG");
        output_assembler("M=D");
        //LCL = frame-4
        output_assembler("@13");
        output_assembler("A=M-1");
        move_back(3);
        output_assembler("D=M");
        output_assembler("@LCL");
        output_assembler("M=D");
        //goto retAddr
        output_assembler("@14");
        output_assembler("A=M");
        output_assembler("0;JMP");
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

    //Add a label
    if (command == "label")
    {
        output_assembler("("+className+"$"+label+")");
    }

    //Goto Command
    if (command == "goto")
    {
        output_assembler("@"+className+"$"+label);
        output_assembler("0;JMP");
    }

    //If-Goto Command
    if (command == "if-goto")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("@"+className+"$"+label);
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

    //Function declaration
    if ( command == "function" )
    {
        output_assembler("("+label+")");
        for (int i = 0; i < number; i++)
        {
            push_zero();
        }
        className = label;
    }

    //Call function
    if (command == "call")
    {
        //push retAddr
        output_assembler("@"+className+"$"+label+to_string(callCalls));
        output_assembler("D=A");
        do_push();
        //push LCL
        output_assembler("@LCL");
        output_assembler("D=M");
        do_push();
        //push ARG
        output_assembler("@ARG");
        output_assembler("D=M");
        do_push();
        //push THIS
        output_assembler("@THIS");
        output_assembler("D=M");
        do_push();
        //push THAT
        output_assembler("@THAT");
        output_assembler("D=M");
        do_push();
        //ARG = SP-nArgs-5
        output_assembler("@SP");
        output_assembler("A=M-1");
        move_back(4+number);
        output_assembler("D=A");
        output_assembler("@ARG");
        output_assembler("M=D");
        //LCL = SP
        output_assembler("@SP");
        output_assembler("D=M");
        output_assembler("@LCL");
        output_assembler("M=D");
        //goto g
        output_assembler("@"+label);
        output_assembler("0;JMP");
        //Label
        output_assembler("("+className+"$"+label+to_string(callCalls)+")");
        callCalls++;
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

    //Push to the stack
    if (command == "push")
    {
        //Push a constant
        if (segment == "constant")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            do_push();
        }

        //Push a static
        if (segment == "static")
        {
            output_assembler("@"+to_string(16+number));
            output_assembler("D=M");
            do_push();
        }

        //Push a local variable
        if (segment == "local")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@LCL");
            output_assembler("A=D+M");
            output_assembler("D=M");
            do_push();
        }

        //Push an argument
        if (segment == "argument")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@ARG");
            output_assembler("A=D+M");
            output_assembler("D=M");
            do_push();
        }

        //Push THIS to the stack
        if (segment == "this")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@THIS");
            output_assembler("A=D+M");
            output_assembler("D=M");
            do_push();
        }

        //Push THAT to the stack
        if (segment == "that")
        {
            output_assembler("@"+to_string(number));
            output_assembler("D=A");
            output_assembler("@THAT");
            output_assembler("A=D+M");
            output_assembler("D=M");
            do_push();
        }

        //Push a pointer
        if (segment == "pointer")
        {
            output_assembler("@"+to_string(3+number));
            output_assembler("D=M");
            do_push();
        }

        //Push a temporary variable
        if (segment == "temp")
        {
            output_assembler("@"+to_string(5+number));
            output_assembler("D=M");
            do_push();
        }

    }

    //Pop from the stack
    if (command == "pop")
    {
        //Pop into a pointer
        if (segment == "pointer")
        {
            do_pop();
            output_assembler("@"+to_string(3+number));
            output_assembler("M=D");
        }

        //Pop into a local variable
        if (segment == "local")
        {
            pop_into("@LCL", number);
        }

        //Pop into an argument
        if (segment == "argument")
        {
            pop_into("@ARG", number);
        }

        //Pop into THIS
        if (segment == "this")
        {
            pop_into("@THIS", number);
        }

        //Pop into THAT
        if (segment == "that")
        {
            pop_into("@THAT", number);
        }

        //Pop into temp
        if (segment == "temp")
        {
            do_pop();
            output_assembler("@"+to_string(5+number));
            output_assembler("M=D");
        }

        //Pop to static
        if (segment == "static")
        {
            do_pop();
            output_assembler("@"+to_string(16+number));
            output_assembler("M=D");
        }

    }

    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// main program
int main(int argc,char **argv)
{
    //Added this to initialise my global variables
    set_numbers();

    // parse abstract syntax tree and pass to the translator
    translate_vm_class(ast_parse_xml()) ;

    // flush output and errors
    print_output() ;
    print_errors() ;
}
