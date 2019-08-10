#include <iostream>
#include <cstdlib>
using namespace std;

class ChangingString
{
    public:
    int distance(string A, string B, int K)
    {
        int elements = A.length();
        int distance = 0;
        int difference[2][elements];


        for (int i = 0; i < elements; i++)
        {
            difference[0][i] = abs((int)A[i] - (int)B[i]);
            difference[1][i] = i;
            cout << difference[1][i] << ": " << difference[0][i] << " | ";
        }
        cout << endl;

        while(true)
        {
            bool sorted = true;

            for (int i = 0; i < elements-1; i++)
            {
                if (difference[0][i] > difference[0][i+1])
                {
                    int tmp = difference[0][i];
                    int tmp2 = difference[1][i];
                    difference[0][i] = difference[0][i+1];
                    difference[1][i] = difference[1][i+1];
                    difference[0][i+1] = tmp;
                    difference[1][i+1] = tmp2;
                    sorted = false;
                }
            }

            if (sorted == true)
            {
                break;
            }

        }

        for(int i = elements-1; i > elements - K - 1; i--)
        {
            difference[0][i] = 0;
        }

        for (int i = 0; i < elements; i++)
        {
            distance = distance + difference[0][i];
            cout << difference[1][i] << ": " << difference[0][i] << " | ";
        }
        cout << endl;

        return distance;
    }
};
