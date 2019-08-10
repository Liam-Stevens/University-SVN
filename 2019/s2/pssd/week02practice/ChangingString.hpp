#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class ChangingString
{
    public:
    int distance(string A, string B, int K)
    {
        int elements = A.length();
        int distance = 0;
        int difference[elements];

        //Find the difference between the strings
        for (int i = 0; i < elements; i++)
        {
            difference[i] = abs((int)A[i] - (int)B[i]);
        }

        //Sort the difference lowest -> highest
        while(true)
        {
            bool sorted = true;

            for (int i = 0; i < elements-1; i++)
            {
                if (difference[i] > difference[i+1])
                {
                    //
                    int tmp = difference[i];
                    difference[i] = difference[i+1];
                    difference[i+1] = tmp;
                    sorted = false;
                }
            }

            if (sorted == true)
            {
                break;
            }

        }

        //Change the highest difference letters to their match
        for(int i = elements-1; i > elements - K - 1; i--)
        {
            //Must change letter even if it is a match
            if(difference[i] == 0)
            {
                difference[i]++;
            } else {
                difference[i] = 0;
            }
        }

        //Sum the difference
        for (int i = 0; i < elements; i++)
        {
            distance = distance + difference[i];
        }

        return distance;
    }
};
