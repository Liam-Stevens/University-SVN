#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class SlowKeyboard
{
    public:
    int enterTime(string time)
    {
        int elements = 5;
        int minutes;
        int seconds;
        int keys[4];
        bool colon = true;

        for (int i = 0; i < elements; i++)
        {
            if(colon == true) {
                if (isdigit (time[i]))
                {
                    minutes = minutes * 10;
                    minutes = minutes + time[i] - 48;
                    keys[i] = time[i] - 48;
                }
                else
                {
                    colon = false;
                }
            } else {
                if (isdigit (time[i]))
                {
                    seconds = seconds * 10;
                    seconds = seconds + time[i] - 48;
                    keys[i] = time[i] - 48;
                }
            }
        }

        int min = 60;

        for(int j = 0; j < min; j++)
        {
            int test = 1;
            for (int i = 1; i < 4; i++)
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
            }

            keys[3]++;
            if (keys[3] > 9)
            {
                keys[3] = 0;
                keys[2]++;
            }
            if (keys[2] > 9)
            {
                keys[2] = 0;
                keys[1]++;
            }
            if (keys[1] > 9)
            {
                keys[1] = 0;
                keys[0]++;
            }
            if (keys[0] > 9)
            {
                keys[0] = 0;
            }

        }

        return min;
    }
};
