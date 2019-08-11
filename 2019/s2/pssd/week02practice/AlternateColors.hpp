#include <iostream>
#include <string>
using namespace std;

class AlternateColors
{
    private:
    long goal;
    bool check(long num) {
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
        long inc = 0;
        long runTime = (r + g + b);
        goal = k;

        for (long i = 0; i < runTime; i++)
        {
            //cout << i << endl;
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
