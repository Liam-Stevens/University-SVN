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

    void disassemble(int num, char target)
    {

        for (int i = 0; i < num; i++)
        {
            original += target;
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
                if (isdigit(text[i+1]))
                {
                    if (isdigit(text[i+2]))
                    {
                        return "TOO LONG";
                    }
                    else
                    {
                        int tmp = text[i] - 48;
                        tmp = tmp * 10;
                        tmp = tmp + text[i+1] - 48;
                        disassemble(tmp, text[i+2]);
                        i = i + 2;
                    }
                }
                else
                {
                    disassemble(text[i] - 48, text[i+1]);
                    i++;
                }
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
