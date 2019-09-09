// a skeleton implementation of a tokeniser

#include "tokeniser.h"
#include <iostream>
#include <ctype.h>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

namespace Assignment_Tokeniser
{

    // is the token of the given kind or does it belong to the given grouping?
    bool token_is_in(Token token,TokenKind kind_or_grouping)
    {
        TokenKind kind = token_kind(token) ;

        // check identity first
        if ( kind == kind_or_grouping ) return true ;

        // this is best written as nested switch statements
        switch(kind_or_grouping)
        {
        default:
            return false ;
        }
    }

    // the current input character, initiliased to ' ' which we ignore
    // the eof marker can be confused with a legal character but not one accepted by our tokeniser
    static char ch = ' ' ;

    // the current line number and column, initialised to line 1 column 0
    static int line_num = 1 ;
    static int column_num = 0 ;

    // the line number and column for the first character in the current token
    static int start_line = 0 ;
    static int start_column = 0 ;

    // generate a context string for the given token
    // it shows the line before the token,
    // the line containing the token up to the end of the token, and
    // a line with a ^ marking the token's position
    // the lines are prefixed by line numbers, right justified in four spaces, followed by ': '
    // if a token extends over more than one line, only the part of the token on the first line is included
    string token_context(Token token)
    {
        return "" ;
    }

    // read next character if not at the end of input
    // and update the line and column numbers
    static void nextch()
    {
        if ( ch == EOF ) return ;

        if ( ch == '\n' )           // if last ch was newline ...
        {
            line_num++ ;            // increment line number
            column_num = 0 ;        // reset column number
        }

        ch = read_char() ;          // read the next character, probably from stdin but this could change during testing
        column_num++ ;              // increment the column number

                                    // additional code will be required here to handle preprocessing of '\t' and '\r'
                                    // you should also consider building a line by line copy of the input for use by token_context()
    }

    ////////////////////////////////////////////////////////////////////////

    //Identifiers
    Token parse_identifier(TokenKind kind,string spelling)
    {
        nextch() ;

        // append characters to spelling until we read past the end of the identifier
        while ( isalnum(ch) || isdigit(ch) || ch == '_' || ch == '$' || ch == '.' )
        {
            spelling += ch ;
            nextch() ;
        }


        return new_token(kind,spelling,start_line,start_column);
    }

    //Complete integer or start of a float
    Token parse_zero(TokenKind kind, string spelling)
    {
        nextch();

        return new_token(kind,spelling,start_line,start_column);
    }

    Token parse_integer(TokenKind kind, string spelling)
    {
        nextch();

        while ( isdigit(ch) )
        {
            spelling += ch;
            nextch();
        }

        return new_token(kind,spelling,start_line,start_column);
    }

    Token parse_single_char_symbol(TokenKind kind,string spelling)
    {
        nextch();

        return new_token(kind,spelling,start_line,start_column);
    }

    //If there is a character included in the multiple character symbols
    Token parse_multiple_char_symbol(TokenKind kind,string spelling)
    {
        nextch();

        if(spelling == "<" && ch == '=')
        {
            spelling += ch ;
            nextch();

            if (ch == '>')
            {
                spelling += ch ;
                nextch();
                return new_token(kind,spelling,start_line,start_column);
            }

        } else if (spelling == "=" && ch == '=')
        {
            spelling += ch;
            nextch();
            return new_token(kind,spelling,start_line,start_column);
        }

        return next_token();
    }

    bool comment_range(char check)
    {
        switch(check)
        {
            case ' '...'~':     return true;
            default:            return false;
        }
    }

    Token parse_comment(TokenKind kind,string spelling)
    {
        nextch();
        if (ch == '/' || ch == '*')
        {
            spelling = "";
            if (ch == '*')
            {
                //Adhoc Comment
                kind = tk_adhoc_comment;
                nextch();
                while (true)
                {
                    if (comment_range(ch))
                    {
                        if (ch == '*')
                        {
                            nextch();
                            if (ch == '/')
                            {
                                nextch();
                                break;
                            } else {
                                spelling += '*';
                                spelling += ch;
                            }
                        } else {
                            spelling += ch;
                        }
                    } else if (ch == '\n')
                    {

                    }
                    nextch();
                }

            } else {
                //End of Line Comment
                kind = tk_eol_comment;
                nextch();
                while (true)
                {
                    if (comment_range(ch))
                    {
                        spelling += ch;
                    } else if (ch == '\n')
                    {
                        nextch();
                        break;
                    }
                    nextch();
                }
            }

        }

        return new_token(kind,spelling,start_line,start_column);
    }


    // called when we find end of input or we an error
    Token parse_eoi()
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        ch = EOF ;

        // return an eoi token
        return new_token(tk_eoi,"",start_line,start_column) ;
    }

    // return the next token object by reading more of the input
    Token next_token()
    {
        // you must read input using the nextch() function
        // the last character read is in the static variable ch
        // always read one character past the end of the token being returned

        string spelling = "" ;

        // this loop reads one character at a time until it reaches end of input
        while ( ch != EOF )
        {
            start_line = line_num ;                 // remember current position in case we find a token
            start_column = column_num ;
            spelling = ch;

            switch(ch)                              // ch is always the next char to read
            {
            case ' ':                               // ignore space and newline
            case '\n':
                nextch() ;                          // read one more character and try again
                break ;
                                                    // add additional case labels here for characters that can start tokens
                                                    // call a parse_*(kind,spelling) function to complete and return each kind of token
                                                    // this should follow the style used in the workshops
                                                    // but remember that the token grammar is different in this assignment
            //Identifiers
            case 'a'...'z':
            case 'A'...'Z':
            case '_':               return parse_identifier(tk_identifier,spelling);

            //Digits
            case '0':               return parse_zero(tk_integer,spelling);
            case '1'...'9':         return parse_integer(tk_integer,spelling);

            //Single Character Symbols
            case '@':               return parse_single_char_symbol(tk_at,spelling);
            case ';':               return parse_single_char_symbol(tk_semi,spelling);
            case ':':               return parse_single_char_symbol(tk_colon,spelling);
            case '!':               return parse_single_char_symbol(tk_not,spelling);
            case ',':               return parse_single_char_symbol(tk_comma,spelling);
            case '.':               return parse_single_char_symbol(tk_stop,spelling);
            case '{':               return parse_single_char_symbol(tk_lcb,spelling);
            case '}':               return parse_single_char_symbol(tk_rcb,spelling);
            case '(':               return parse_single_char_symbol(tk_lrb,spelling);
            case ')':               return parse_single_char_symbol(tk_rrb,spelling);
            case '[':               return parse_single_char_symbol(tk_lsb,spelling);
            case ']':               return parse_single_char_symbol(tk_rsb,spelling);

            //Multiple Character Symbols
            //case '=':              return parse_multiple_char_symbol(tk_eq,spelling);
            case '<':              return parse_multiple_char_symbol(tk_spaceship,spelling);

            //Parse Comments
            case '/':               return parse_comment(tk_div,spelling);


            default:
                return parse_eoi() ;                // the next character cannot start a token, this is an error, return an EOI token
            }
        }

        start_line = line_num ;                     // remember current position so EOI token is correct
        start_column = column_num ;

        return parse_eoi() ;                         // return an EOI token
    }
}
