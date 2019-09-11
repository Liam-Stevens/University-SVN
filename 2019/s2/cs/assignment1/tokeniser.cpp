// a skeleton implementation of a tokeniser

#include "tokeniser.h"
#include <iostream>
#include <ctype.h>
#include <vector>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

namespace Assignment_Tokeniser
{
    // is the token of the given kind or does it belong to the given grouping?
    bool token_kind_is_in(TokenKind kind,TokenKind kind_or_grouping)
    {

        // check identity first
        if ( kind == kind_or_grouping ) return true ;

        // this is best written as nested switch statements
        switch(kind_or_grouping)
        {
            case tk_number:
                switch(kind)
                {
                    case tk_integer:
                    case tk_float:
                        return true;
                    default:
                        return false;
                }
            case tk_keyword:
                switch(kind)
                {
                    case tk_do:
                    case tk_for:
                    case tk_pointer:
                    case tk_real:
                    case tk_this:
                        return true;
                    default:
                        return false;
                }
            case tk_symbol:
                switch(kind)
                {
                    case tk_at:
                    case tk_semi:
                    case tk_colon:
                    case tk_not:
                    case tk_comma:
                    case tk_stop:
                    case tk_eq:
                    case tk_spaceship:
                    case tk_lcb:
                    case tk_rcb:
                    case tk_lrb:
                    case tk_rrb:
                    case tk_lsb:
                    case tk_rsb:
                    case tk_div:
                        return true;
                    default:
                        return false;
                }
            default:
                return false;
        }
    }

    bool token_is_in(Token token,TokenKind kind_or_grouping)
    {
        TokenKind kind = token_kind(token) ;

        return token_kind_is_in(kind,kind_or_grouping);
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

    static vector<string> input_line(1,"");

    int context_token_num = 0;

    // generate a context string for the given token
    // it shows the line before the token,
    // the line containing the token up to the end of the token, and
    // a line with a ^ marking the token's position
    // the lines are prefixed by line numbers, right justified in four spaces, followed by ': '
    // if a token extends over more than one line, only the part of the token on the first line is included
    string token_context(Token token)
    {
        string spelling = token_spelling(token);
        int token_length = spelling.length();
        int found_line = token_line(token);
        int found_column = token_column(token);

        //Print all lines before the current line
        if (found_line > 1)
        {
            cout << "   " << found_line-1 << ": " << input_line[found_line-2];
        }

        //Print current lines
        cout << "   " << found_line << ": ";
        if (token_kind(token) == tk_eol_comment || token_kind(token) == tk_adhoc_comment)
        {
            //COMMENT PRINT
            for (int i = 0; i < input_line[found_line-1].length(); i++)
            {
                if (token_kind(token) == tk_eol_comment && input_line[found_line-1][i] == '\n')
                {
                    break;
                }
                cout << input_line[found_line-1][i];
            }

        } else {
            //If it is not a special token
            for (int i = 0; i < found_column + token_length - 1; i++)
            {
                if ( i >= found_column)
                {
                    if (input_line[found_line-1][i] != spelling[i - found_column + 1])
                    {
                        //cout << endl << "CONFLICT: " << input_line[found_line-1][i] << " | " << spelling[i - found_column + 1] << endl;
                        break;
                    }
                }
                cout << input_line[found_line-1][i];
            }
        }
        cout << endl;

        //Print arrow
        for (int i = 0; i < found_column+5; i++)
        {
            cout << ' ';
        }
        cout << '^' << endl;

        return "";
    }

    // read next character if not at the end of input
    // and update the line and column numbers
    static void nextch()
    {
        if ( ch == EOF ) return ;

        char lastChar = ch;

        if ( ch == '\n' )           // if last ch was newline ...
        {
            line_num++ ;            // increment line number
            column_num = 0 ;        // reset column number
            input_line.push_back("");
        }

        ch = read_char();           // read the next character, probably from stdin but this could change during testing
        column_num++;               // increment the column number

                                    // additional code will be required here to handle preprocessing of '\t' and '\r'
                                    // you should also consider building a line by line copy of the input for use by token_context()
        if ( ch == '\t' )
        {
            int increment = column_num%4;
            column_num = column_num + 4 - increment;
            ch = ' ';

            for (int i = increment; i < 4; i++)
            {
                input_line[line_num-1] += ch;
            }
        }

        if ( ch == '\r' )
        {
            ch = read_char();
            if (ch != '\n')
            {
                ch = '\n';
            }
        }

        input_line[line_num-1] += ch;

    }

    ////////////////////////////////////////////////////////////////////////

    // called when we find end of input or we an error
    Token parse_eoi()
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        ch = EOF ;

        // return an eoi token
        return new_token(tk_eoi,"",start_line,start_column) ;
    }

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

        //Find if it is a keyword
        kind = string_to_token_kind(spelling);

        if ( !token_kind_is_in(kind,tk_keyword) )
        {
            kind = tk_identifier;
        }

        return new_token(kind,spelling,start_line,start_column);
    }

    //The exponent in a float
    Token parse_exponent(TokenKind kind, string spelling)
    {
        nextch();

        if (ch == '+' || ch == '-')
        {
            spelling += ch;
            nextch();
        } else {
            spelling += '+';
        }

        if (ch == '0')
        {
            spelling += ch;
            nextch();
        } else if (isdigit(ch)) {

            while ( isdigit(ch) )
            {
                spelling += ch;
                nextch();
            }

        } else {
            return parse_eoi();
        }

        if (spelling[spelling.length()-1] == '+' || spelling[spelling.length()-1] == '-')
        {
            spelling += '0';
        }

        return new_token(kind,spelling,start_line,start_column);
    }

    //Floating point numbers
    Token parse_float(TokenKind kind, string spelling, bool leading)
    {
        nextch();
        if(leading == false)
        {
            if(isdigit(ch) == false)
            {
                kind = tk_stop;
                return new_token(kind,spelling,start_line,start_column);
            } else {
                spelling = "0.";
            }
        }

        while ( isdigit(ch) || ch == 'e' || ch == 'E')
        {
            if (ch == 'e' || ch == 'E')
            {
                if(spelling[spelling.length()-1] == '.')
                {
                    spelling += '0';
                }
                spelling += 'e';
                return parse_exponent(kind,spelling);
            }

            spelling += ch;

            nextch();
        }

        if (spelling[spelling.length()-1] == '.')
        {
            spelling += '0';
        }

        spelling = spelling + 'e' + '+' + '0';

        return new_token(kind,spelling,start_line,start_column);
    }

    //Complete integer or start of a float
    Token parse_zero(TokenKind kind, string spelling)
    {
        nextch();

        if (ch == '.')
        {
            spelling += ch;
            return parse_float(tk_float,spelling,true);
        }

        if (ch == 'e' || ch == 'E')
        {
            spelling += 'e';
            return parse_exponent(tk_float,spelling);
        }

        return new_token(kind,spelling,start_line,start_column);
    }

    //All integers
    Token parse_integer(TokenKind kind, string spelling)
    {
        nextch();

        while ( isdigit(ch) )
        {
            spelling += ch;
            nextch();
        }

        if (ch == '.')
        {
            spelling += ch;
            return parse_float(tk_float,spelling,true);
        }

        if (ch == 'e' || ch == 'E')
        {
            spelling += 'e';
            return parse_exponent(tk_float,spelling);
        }

        return new_token(kind,spelling,start_line,start_column);
    }

    bool validate_string(char check)
    {
        switch(check)
        {
            case ' ':
            case '!':
            case '#'...'~':     return true;
            default:            return false;
        }
    }

    //Strings
    Token parse_string(TokenKind kind,string spelling)
    {
        nextch();

        while (ch != '"')
        {
            if(validate_string(ch))
            {
                spelling += ch;
                nextch();
            } else {
                return parse_eoi();
            }
        }
        nextch();

        return new_token(kind,spelling,start_line,start_column);
    }

    //Single Character Symbols
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

        return parse_eoi();
    }

    //Determine if a comment character
    bool comment_range(char check)
    {
        switch(check)
        {
            case ' '...'~':     return true;
            default:            return false;
        }
    }

    //EOL and ADHOC comments
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
                        spelling += ch;
                    } else {
                        parse_eoi();
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
            case '.':               return parse_float(tk_float,spelling,false);

            //Single Character Symbols
            case '@':               return parse_single_char_symbol(tk_at,spelling);
            case ';':               return parse_single_char_symbol(tk_semi,spelling);
            case ':':               return parse_single_char_symbol(tk_colon,spelling);
            case '!':               return parse_single_char_symbol(tk_not,spelling);
            case ',':               return parse_single_char_symbol(tk_comma,spelling);
            case '{':               return parse_single_char_symbol(tk_lcb,spelling);
            case '}':               return parse_single_char_symbol(tk_rcb,spelling);
            case '(':               return parse_single_char_symbol(tk_lrb,spelling);
            case ')':               return parse_single_char_symbol(tk_rrb,spelling);
            case '[':               return parse_single_char_symbol(tk_lsb,spelling);
            case ']':               return parse_single_char_symbol(tk_rsb,spelling);

            //Multiple Character Symbols
            case '=':              return parse_multiple_char_symbol(tk_eq,spelling);
            case '<':              return parse_multiple_char_symbol(tk_spaceship,spelling);

            //Parse Comments
            case '/':               return parse_comment(tk_div,spelling);

            //Parse Strings
            case '"':               return parse_string(tk_string,"");


            default:
                return parse_eoi() ;                // the next character cannot start a token, this is an error, return an EOI token
            }
        }

        start_line = line_num ;                     // remember current position so EOI token is correct
        start_column = column_num ;

        return parse_eoi() ;                         // return an EOI token
    }
}
