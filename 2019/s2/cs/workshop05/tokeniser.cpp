// tokeniser implementation for the workshop example language

#include "tokeniser.h"
#include <ctype.h>

// to shorten the code
using namespace std ;

// we are extending the Workshop_Tokeniser namespace

namespace Workshop_Tokeniser
{
    // parse a single character symbol
    // we know spelling is the one character symbol
    // the caller already knows the kind and spelling so they are passed as parameters
    // if they were not we would have to repeat the switch statement to find out
    static Token parse_single_char_symbol(TokenKind kind,string spelling)
    {
        // always read the next character - we have read past the end of the token
        nextch() ;



        // return a new Token object
        return new_token(kind,spelling) ;
    }

    static Token parse_multiple_char_symbol(TokenKind kind,string spelling)
    {
        // always read the next character - we have read past the end of the token
        nextch() ;

        while ( ch == '<' || ch == '>' || ch == '=' || ch == '!' )
        {
            if ((spelling == "<=") || (spelling == "==") || (spelling == "!=") || (spelling == ">=")) {
                break;
            } else if ((spelling == "<" && ch != '=') || (spelling == ">" && ch != '=') || (spelling == "!" && ch != '=' ) || (spelling == "=" && ch != '=')) {
                break;
            }

            spelling += ch ;
            nextch() ;
        }

        if (spelling == "<=")
        {
            return new_token(tk_le,spelling);
        } else if (spelling == "==")
        {
            return new_token(tk_eq,spelling);
        } else if (spelling == "!=")
        {
            return new_token(tk_ne,spelling);
        } else if (spelling == ">=")
        {
            return new_token(tk_ge,spelling);
        } else if (spelling == "!") {
            return next_token();
        } else {
            return new_token(kind,spelling);
        }

    }

    // parse a number - always read one extra character
    // we know spelling is the first digit of the number
    static Token parse_integer(TokenKind kind,string spelling)
    {
        // always read the next character
        nextch() ;

        // append digits to spelling until we read past the end of the integer
        while ( isdigit(ch) )
        {
            spelling += ch ;
            nextch() ;
        }

        // return a new Token object
        return new_token(kind,spelling) ;
    }

    static Token parse_identifier(TokenKind kind,string spelling)
    {
        // always read the next character
        nextch() ;

        // append characters to spelling until we read past the end of the identifier
        while ( isalnum(ch) || isdigit(ch) )
        {
            spelling += ch ;
            nextch() ;
        }

        //
        if (spelling == "var")
        {
            return new_token(tk_var,spelling);
        } else if (spelling == "while") {
            return new_token(tk_while,spelling);
        } else if (spelling == "if") {
            return new_token(tk_if,spelling);
        } else if (spelling == "else") {
            return new_token(tk_else,spelling);
        } else if (spelling == "let") {
            return new_token(tk_let,spelling);
        } else {
            return new_token(kind,spelling);
        }

        // return a new Token object
        return new_token(kind,spelling);
    }

    // parse end of input - report we have reached end of input
    // simulate end of input to prevent further attemps to read input
    static Token parse_eoi(TokenKind kind,string spelling)
    {
        // if called after an error we may not be at the end of input so simulate it
        ch = EOF ;

        // return a new Token object
        return new_token(kind,spelling) ;
    }

    // return the next Token object by reading more of the input
    // this function simply searches for the start of a token
    // then calls the appropriate parse function to complete the Token object
    Token next_token()
    {
        string spelling = "" ;

        while ( ch != EOF )	            // loop until EOF or the start of a token is found
        {
            spelling = ch ;             // initialise spelling with first character

            switch(ch)			        // ch is always the next char to read
            {
            case ' ':			        // ignore whitespace (space, tab, carriage return, line feed)
            case '\t':
            case '\r':
            case '\n':
                            nextch() ;  // read next character and go around again
                            break ;

                                        // when we find the first character of a token
                                        // call a function to read all of its characters
                                        // and construct an appropriate Token object

            //Single Character Symbols
            case '@':       return parse_single_char_symbol(tk_at,spelling);
            case '{':       return parse_single_char_symbol(tk_lcb,spelling);
            case '}':       return parse_single_char_symbol(tk_rcb,spelling);
            case '(':       return parse_single_char_symbol(tk_lrb,spelling);
            case ')':       return parse_single_char_symbol(tk_rrb,spelling);
            case ':':       return parse_single_char_symbol(tk_colon,spelling);
            case ';':       return parse_single_char_symbol(tk_semi,spelling);
            case '.':       return parse_single_char_symbol(tk_dot,spelling);
            case ',':       return parse_single_char_symbol(tk_comma,spelling);
            case '"':       return parse_single_char_symbol(tk_dquote,spelling);

            //Multi Character Symbols
            case '=':       return parse_multiple_char_symbol(tk_assign,spelling);
            case '>':       return parse_multiple_char_symbol(tk_gt,spelling);
            case '<':       return parse_multiple_char_symbol(tk_lt,spelling);
            case '!':       return parse_multiple_char_symbol(tk_ne,spelling);


            //Math
            case '+':       return parse_single_char_symbol(tk_add,spelling);
            case '-':       return parse_single_char_symbol(tk_sub,spelling);
            case '*':       return parse_single_char_symbol(tk_times,spelling);
            case '/':       return parse_single_char_symbol(tk_divide,spelling);

            //Identifiers
            case 'a'...'z': return parse_identifier(tk_identifier,spelling) ;
            case 'A'...'Z': return parse_identifier(tk_identifier,spelling) ;

            //Digits
            case '0'...'9': return parse_integer(tk_integer,spelling) ;

            default:			        // anything unexpected - pretend we reached the end of the input
                            return parse_eoi(tk_eoi,"");
            }
        }
        return parse_eoi(tk_eoi,"");            // assume we are at the end of the input
    }
}
