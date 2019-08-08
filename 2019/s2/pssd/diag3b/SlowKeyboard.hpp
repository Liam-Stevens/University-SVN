#include <vector>
#include <string>
#include <iostream>
#include <ctype.h>
using namespace std;

class SlowKeyboard
{
    public:
    int enterTime(string time1)
    {
        int elements = 5;
        int minutes = 0;
        int seconds = 0;
        int minutes2 = 0;
        int seconds2 = 0;
        int keys[5];
        bool colon = true;

        for (int i = 0; i < elements; i++)
        {
            if(colon == true) {
                if (isdigit (time1[i]))
                {
                    minutes = minutes * 10;
                    minutes = minutes + time1[i] - 48;
                    keys[i] = time1[i] - 48;
                }
                else
                {
                    colon = false;
                }
            } else {
                if (isdigit (time1[i]))
                {
                    seconds = seconds * 10;
                    seconds = seconds + time1[i] - 48;
                    keys[i] = time1[i] - 48;
                }
            }
        }

        int min = 60;

        for(int j = 0; j < min; j++)
        {
            int test = 1;
            for (int i = 1; i < 5; i++)
            {
                if(keys[i] != keys[i-1])
                {
                    test = test + 2;
                }
                test++;
            }

            if (test < min)
            {
                min = test;
                minutes2 = 10*keys[0] + keys[1];
                seconds2 = 10*keys[3] + keys[4];
            }

            //cout << "Test " << j+1 << ": "<< keys[0] << keys[1] << ":" << keys[3] << keys[4] << endl;

            keys[3]++;
            if (keys[4] > 9)
            {
                keys[4] = 0;
                keys[3]++;
            }
            if (keys[3] > 5)
            {
                keys[2] = 0;
                keys[1]++;
            }
            if (keys[1] > 9)
            {
                keys[1] = 0;
                keys[0]++;
            }
            if (keys[0] > 5)
            {
                keys[0] = 0;
            }
        }

        //cout << minutes << ":" << seconds << endl;
        //cout << minutes2 << ":" << seconds2 << endl;


        return min;
    }
};
