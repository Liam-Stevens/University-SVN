#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Multiples
{
public:
    int number(int min, int max, int factor)
    {      
        long num = 0;

        for (int i = min; i <= max; i++)
        {
            if (i%factor == 0)
            {
                num++;
            }
        }

        return num;
    }
};
