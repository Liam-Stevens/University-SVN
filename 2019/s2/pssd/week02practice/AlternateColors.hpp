#include <iostream>
#include <string>
using namespace std;

class AlternateColors
{
    private:
    bool check(long goal) {
        if(goal == 0) {
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

        for (long i = 0; i < runTime; i++)
        {
            //cout << i << endl;
            if(r > 1000 && g > 1000 && b > 1000 && k > 1000) {
                //All Reduction
                r = r/10;
                g = g/10;
                b = b/10;
                k = k/10;
                //cout << "Executed at: R " << r << " G " << g << " B " << b << " K " << k << endl;

            } else if (r > 1000 && g > 1000  && k > 1000) {
                //Red and Green Reduction
                r = r/10;
                g = g/10;
                k = k/10;
                //cout << "Executed at: R " << r << " G " << g << " K " << k << endl;

            } else if (r > 1000 && b > 1000 && k > 1000) {
                //Red and Blue Reduction
                r = r/10;
                b = b/10;
                k = k/10;
                //cout << "Executed at: R " << r << " B " << b << " K " << k << endl;

            } else if (g > 1000 && b > 1000 && k > 1000) {
                //Green and Blue Reduction
                g = g/10;
                b = b/10;
                k = k/10;
                //cout << "Executed at: G " << g << " B " << b << " K " << k << endl;

            }

            if(r > 0)
            {
                r--;
                k--;
                if (check(k))
                {
                    color = "RED";
                    break;
                }
            }
            if(g > 0)
            {
                g--;
                k--;
                if (check(k))
                {
                    color = "GREEN";
                    break;
                }
            }
            if(b > 0)
            {
                b--;
                k--;
                if (check(k))
                {
                    color = "BLUE";
                    break;
                }
            }

            if (r == 0 && g == 0)
            {
                color = "BLUE";
                break;
            }
            if (g == 0 && b == 0)
            {
                color = "RED";
                break;
            }
            if (b == 0 && r == 0)
            {
                color = "GREEN";
                break;
            }

        }

        return color;
    }
};
