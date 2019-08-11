#include <iostream>
#include <string>
using namespace std;

class AlternateColors
{
    private:
    int goal;
    bool check(int num) {
        if(goal == num) {
            return true;
        } else {
            return false;
        }
    }

    public:
    string getColor(long r, long g, long b, long k)
    {
        string color = "NONE";
        int inc = 0;
        int runTime = (int)(r + g + b);
        goal = (int)k;

        for (int i = 0; i < runTime; i++)
        {
            if(r > 0)
            {
                r--;
                inc++;
                if (check(inc))
                {
                    color = "RED";
                    break;
                }
            }
            if(g > 0)
            {
                g--;
                inc++;
                if (check(inc))
                {
                    color = "GREEN";
                    break;
                }
            }
            if(b > 0)
            {
                b--;
                inc++;
                if (check(inc))
                {
                    color = "BLUE";
                    break;
                }
            }
        }

        return color;
    }
};
