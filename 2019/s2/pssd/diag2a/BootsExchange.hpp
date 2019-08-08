#include <vector>
#include <iostream>
using namespace std;

class BootsExchange
{
    public:
    int leastAmount(vector<int> left,vector<int> right)
    {
        int elements = left.size();
        int diff = 0;

        while(true) 
        {
            bool sortedLeft = true;
            bool sortedRight = true;

            if (elements > 1) 
            {
                for (int i = 0; i < elements-1; i++)
                {
                    if (left[i] > left[i+1])
                    {
                        int tmp = left[i+1];
                        left[i+1] = left[i];
                        left[i] = tmp;
                        sortedLeft = false;
                    }

                    if (right[i] > right[i+1])
                    {
                        int tmp2 = right[i+1];
                        right[i+1] = right[i];
                        right[i] = tmp2;
                        sortedRight = false;
                    }
                }
            }

            if (sortedLeft == true && sortedRight == true)
            {
                break;
            }
        }

        for (int i = 0; i < elements; i++)
        {
            if(left[i] != right[i])
            {
                diff++;
            }
        }

        return diff;
    }
};
