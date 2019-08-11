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
    long findMultiple(long in1,long in2, long in3, long in4)
    {
        long ans = 0;
        for(int i = 0; i < in1; i++)
        {
                ans++;
                if(ans % in1 == 0 && ans % in2 == 0 && ans % in3 == 0 && ans % in4 == 0)
                {
                    break;
                }
        }
        return ans;
    }
    long findMultiple(long in1,long in2, long in3)
    {
        long ans = 0;
        for(int i = 0; i < in1; i++)
        {
                ans++;
                if(ans % in1 == 0 && ans % in2 == 0 && ans % in3 == 0)
                {
                    break;
                }
        }
        return ans;
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
                long multiple = findMultiple(r,g,b,k);
                r = r/multiple;
                g = g/multiple;
                b = b/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " G " << g << " B " << b << " K " << k << endl;

            } else if (r > 1000 && g > 1000  && k > 1000) {
                //Red and Green Reduction
                long multiple = findMultiple(r,g,k);
                r = r/multiple;
                g = g/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " G " << g << " K " << k << endl;

            } else if (r > 1000 && b > 1000 && k > 1000) {
                //Red and Blue Reduction
                long multiple = findMultiple(r,b,k);
                r = r/multiple;
                b = b/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " B " << b << " K " << k << endl;

            } else if (g > 1000 && b > 1000 && k > 1000) {
                //Green and Blue Reduction
                long multiple = findMultiple(g,b,k);
                g = g/multiple;
                b = b/multiple;
                k = k/multiple;
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
