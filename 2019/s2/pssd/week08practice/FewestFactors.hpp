#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FewestFactors
{
private:
    int minPerms;
    int chosen;

    int factors(int num)
    {
        int amount = 0;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                amount++;
            }
        }
        return amount;
    }

    int buildNum(vector<int> digits)
    {
        int build = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            build = build * 10;
            build = build+digits[i];
        }
        return build;
    }

    void permutations(vector<int> digits, int num1, int num2)
    {
        if (num1 == num2)
        {
            int uniqueNumber = buildNum(digits);
            int factor = factors(uniqueNumber);
            if (factor < minPerms)
            {
                minPerms = factor;
                chosen = uniqueNumber;
            }
            else if (factor == minPerms && chosen > uniqueNumber)
            {
                chosen = uniqueNumber;
            }
        }
        else
        {
            for (int i = num1; i <= num2; i++)
            {
                int tmp = digits[num1];
                digits[num1] = digits[i];
                digits[i] = tmp;
                permutations(digits, num1+1, num2);
                tmp = digits[num1];
                digits[num1] = digits[i];
                digits[i] = tmp;
            }
        }
    }

public:
    int number(vector<int> digits)
    {
        minPerms = 99999;
        chosen = -1;

        permutations(digits, 0, digits.size()-1);
        
        return chosen;
    }
};
