#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SimpleCompressor
{
private:
    string expand(string parse, int point1, int point2)
    {

        string front;
        if (point1 > 0)
        {
            front = parse[0];

            if (point1 > 1)
            {

                for (int i = 1; i < point1; i++)
                {
                    front += parse[i];
                }
            }
        }

        string back;
        if (point2 < parse.length()-1)
        {
            back = parse[point2+1];

            if (point2 < parse.length()-2)
            {

                for (int i = point2+2; i < parse.length(); i++)
                {
                    back += parse[i];
                }
            }
        }

        int repeats = parse[point1+1] - 48;
        string middle;
        middle = parse[point1+2];
        for(int i = point1+3; i < point2; i++)
        {
            middle += parse[i];
        }



        string full;
        full.append(front);

        for (int i = 0; i < repeats; i++)
        {
            full.append(middle);
        }

        full.append(back);

        return full;
    }

public:
    string uncompress(string data)
    {
        bool finished = false;
        do
        {
            finished = true;

            int opening = -1;
            int closing = -1;

            for (int i = 0; i < data.length(); i++)
            {
                if (data[i] == '[')
                {
                    finished = false;
                    opening = i;
                } else if (data[i] == ']')
                {
                    closing = i;
                    data = expand(data,opening,closing);
                    break;
                }
            }

        } while (finished == false);

        return data;
    }
};
