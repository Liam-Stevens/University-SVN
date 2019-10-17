#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

class RunLengthEncoding
{
private:
string original;
int length;

    void disassemble(int index, string text)
    {

        for (int i = 0; i < text[index] - 48; i++)
        {
            original += text[index+1];
            length++;

            if (length > 50)
            {
                return;
            }
        }

    }

public:
    string decode(string text)
    {
        original = "";
        length = 0;

        for (int i = 0; i < text.length(); i++)
        {

            if (isdigit(text[i]))
            {
                disassemble(i,text);
                i++;
            }
            else
            {
                original += text[i];
                length++;
            }

            if (length > 50)
            {
                return "TOO LONG";
            }

        }


        return original;
    }
};
