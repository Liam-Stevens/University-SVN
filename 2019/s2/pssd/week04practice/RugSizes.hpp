#include <iostream>
using namespace std;

class RugSizes
{
public:
    int rugCount(int area)
    {
        int sizes = 0;

        for (int i = 1; i <= area/2; i++)
        {
            int test = area/i;
            if(i % 2 == 0 && test % 2 == 0)
            {

            } else {
                if (test*i == area)
                {
                    sizes++;
                }
            }
        }

        return sizes;
    }
};
