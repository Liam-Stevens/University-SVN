#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FracCount
{
private:
    int greatestCommonFactor(int num1, int num2)
    {
        if (num1 == 0)
        {
            return num2;
        }
        return greatestCommonFactor(num2 % num1, num1);
    }

public:
    int position(int numerator, int denominator)
    {
        int pos = 1;
        int num = 1;
        int den = 2;

        while (true)
        {
            if (num == numerator && den == denominator)
            {
                return pos;
            } 
            if (den > denominator)
            {
                return -1;
            }

            pos++;
            num++;
            if (num == den)
            {
                num = 1;
                den++;
            }

            while (greatestCommonFactor(num,den) != 1)
            {
                //cout << num << "/" << den << " | GCD: " << greatestCommonFactor(num,den) << endl;
                num++;
                if (num == den)
                {
                    num = 1;
                    den++;
                }
            }


        }

        return pos;
    }
};
