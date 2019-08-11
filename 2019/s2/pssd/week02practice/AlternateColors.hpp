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
        bool found = false;
        for(int i = 0; i < 10000; i++)
        {
                ans++;
                if(ans % in1 == 0 && ans % in2 == 0 && ans % in3 == 0 && ans % in4 == 0)
                {
                    //cout << "!" << ans << endl;
                    found = true;
                    break;
                }
                //cout << ans << endl;
        }
        if (found == true)
        {
            return ans;
        }  else {
            return 1;
        }
    }
    long findMultiple(long in1,long in2, long in3)
    {
        long ans = 0;
        bool found = false;
        for(int i = 0; i < 10000; i++)
        {
                ans++;
                if(ans % in1 == 0 && ans % in2 == 0 && ans % in3 == 0)
                {
                    //cout << "!" << ans << endl;
                    found = true;
                    break;
                }
                //cout << ans << endl;
        }
        if (found == true)
        {
            return ans;
        }  else {
            return 1;
        }
    }

    public:
    string getColor(long r, long g, long b, long k)
    {
        string color = "NONE";
        long inc = 0;
        long runTime = (r + g + b);
        int none = 0;
        long min = r;
        int minPoint = 0;
        bool zero[3];
        int zeroes = 0;
        int index = k;

        for (int i = 0; i < 3; i++)
        {
            zero[i] = false;
        }


        //Reduce to series
        for (int i = 0; i < 3; i++)
        {
            if(r != 0)
            {
                min = r;
            } else if (g != 0) {
                min = g;
            } else if (b != 0) {
                min = b;
            }

            if (r == 0 && zero[0] == false)
            {
                zero[0] = true;
                zeroes++;
            }
            if (g == 0 && zero[1] == false)
            {
                zero[1] = true;
                zeroes++;
            }
            if (b == 0 && zero[2] == false)
            {
                zero[2] = true;
                zeroes++;
            }

            if(r < min && zero[0] == false)
            {
                min = r;
                minPoint = 0;
            }
            if(g < min && zero[1] == false)
            {
                min = g;
                minPoint = 1;
            }
            if(b < min && zero[2] == false)
            {
                min = b;
                minPoint = 2;
            }

            //cout << "R " << r << " G " << g << " B " << b << " Min " << min << " Zeroes " << zeroes << endl;
            if ((min*(3-zeroes)) <= k && zeroes < 2)
            {
                if(zero[0] == false)
                {
                    r = r-min;
                }
                if(zero[1] == false)
                {
                    g = g-min;
                }
                if(zero[2] == false)
                {
                    b = b-min;
                }
                k = k-(min*(3-zeroes));

                if(k == 0) {
                    if (minPoint == 0)
                    {
                        color = "RED";
                        break;
                    }
                    else if (minPoint == 1)
                    {
                        color = "GREEN";
                        break;
                    }
                    else if (minPoint == 2)
                    {
                        color = "BLUE";
                        break;
                    }
                }
            }
        }

        int remain = k%(3-zeroes);
        //cout << remain << zeroes << endl;
        if(remain == 0 && zeroes == 0) {
            color = "BLUE";
        } else if (remain == 1 && zeroes == 0) {
            color = "RED";
        } else if (remain == 2 && zeroes == 0) {
            color = "GREEN";
        } else if (remain == 0 && zeroes == 1 && zero[0] == true) {
            color = "BLUE";
        } else if (remain == 0 && zeroes == 1 && zero[1] == true) {
            color = "BLUE";
        } else if (remain == 0 && zeroes == 1 && zero[2] == true) {
            color = "GREEN";
        } else if (remain == 1 && zeroes == 1 && zero[0] == true) {
            color = "GREEN";
        } else if (remain == 1 && zeroes == 1 && zero[1] == true) {
            color = "RED";
        } else if (remain == 1 && zeroes == 1 && zero[2] == true) {
            color = "RED";
        } else if (zeroes == 2 && zero[0] == false) {
            color = "RED";
        } else if (zeroes == 2 && zero[1] == false) {
            color = "GREEN";
        } else if (zeroes == 2 && zero[2] == false) {
            color = "BLUE";
        }


        /*
        for (long i = 0; i < runTime; i++)
        {

            //Find the lowest common multiple
            if(r > 10000 && g > 10000 && b > 10000 && k > 10000 && none < 10000) {
                //All Reduction
                long multiple = findMultiple(r,g,b,k);
                if (multiple == 1)
                {
                    none++;
                }
                r = r/multiple;
                g = g/multiple;
                b = b/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " G " << g << " B " << b << " K " << k << endl;
            } else if (r > 10000 && g > 10000  && k > 10000 && none < 10000) {
                //Red and Green Reduction
                long multiple = findMultiple(r,g,k);
                if (multiple == 1)
                {
                    none++;
                }
                r = r/multiple;
                g = g/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " G " << g << " K " << k << endl;
            } else if (r > 10000 && b > 10000 && k > 10000 && none < 10000) {
                //Red and Blue Reduction
                long multiple = findMultiple(r,b,k);
                if (multiple == 1)
                {
                    none++;
                }
                r = r/multiple;
                b = b/multiple;
                k = k/multiple;
                //cout << "Executed at: R " << r << " B " << b << " K " << k << endl;
            } else if (g > 10000 && b > 10000 && k > 10000 && none < 10000) {
                //Green and Blue Reduction
                long multiple = findMultiple(g,b,k);
                if (multiple == 1)
                {
                    none++;
                }
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

        }*/

        return color;
    }
};
