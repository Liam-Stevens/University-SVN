#include <iostream>
#include <string>
using namespace std;

class AlternateColors
{
    public:
    string getColor(long r, long g, long b, long k)
    {
        //Initialize
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
            //Ensure a non-zero minimum exists
            if(r != 0)
            {
                min = r;
            } else if (g != 0) {
                min = g;
            } else if (b != 0) {
                min = b;
            }

            //Determine which has nothing left
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

            //Find the minimum
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

            //Reduce the scope of the problem
            if ((min*(3-zeroes)) <= k && zeroes < 2)
            {
                //Reduce everything by a factor of minimum
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

                //If k is reduced to nothing, find the result
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

        //Calculate the remainer
        int remain = k%(3-zeroes);

        //Large If block to determine the colour
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

        return color;
    }
};
