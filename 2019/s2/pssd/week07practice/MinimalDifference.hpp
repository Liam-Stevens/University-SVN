#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class MinimalDifference
{
private:
    int digitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum = sum + num%10;
            num = num / 10;
        }
        return sum;
    }

public:
    int findNumber(int A, int B, int C)
    {
        C = digitSum(C);

        int minDiff = B+1;
        int currentNum = B;

        for(int i = A; i <= B; i++)
        {
            int tmp = abs(C-digitSum(i));
            if (tmp < minDiff)
            {
                minDiff = tmp;
                
                currentNum = i;
            }

            
        }

        return currentNum;
    }
};
