#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UnsealTheSafe
{
private:
    long recursivePassword(int digit, int N)
    {
        if (N <= 1)
        {
            return 1;
        }

        if (digit == 1)
        {
            long tmp1 = recursivePassword(2,N-1);
            long tmp2 = recursivePassword(4,N-1);
            return tmp1 + tmp2;
        } else if (digit == 2) {
            long tmp1 = recursivePassword(1,N-1);
            long tmp2 = recursivePassword(5,N-1);
            long tmp3 = recursivePassword(3,N-1);
            return tmp1 + tmp2 + tmp3;
        } else if (digit == 3) {
            long tmp1 = recursivePassword(2,N-1);
            long tmp2 = recursivePassword(6,N-1);
            return tmp1 + tmp2;
        } else if (digit == 4) {
            long tmp1 = recursivePassword(1,N-1);
            long tmp2 = recursivePassword(5,N-1);
            long tmp3 = recursivePassword(7,N-1);
            return tmp1 + tmp2 + tmp3;
        } else if (digit == 5) {
            long tmp1 = recursivePassword(2,N-1);
            long tmp2 = recursivePassword(6,N-1);
            long tmp3 = recursivePassword(8,N-1);
            long tmp4 = recursivePassword(4,N-1);
            return tmp1 + tmp2 + tmp3 + tmp4;
        } else if (digit == 6) {
            long tmp1 = recursivePassword(9,N-1);
            long tmp2 = recursivePassword(5,N-1);
            long tmp3 = recursivePassword(3,N-1);
            return tmp1 + tmp2 + tmp3;
        } else if (digit == 7) {
            long tmp1 = recursivePassword(4,N-1);
            long tmp2 = recursivePassword(8,N-1);
            long tmp3 = recursivePassword(0,N-1);
            return tmp1 + tmp2 + tmp3;
        } else if (digit == 8) {
            long tmp1 = recursivePassword(7,N-1);
            long tmp2 = recursivePassword(5,N-1);
            long tmp3 = recursivePassword(9,N-1);
            return tmp1 + tmp2 + tmp3;
        } else if (digit == 9) {
            long tmp1 = recursivePassword(8,N-1);
            long tmp2 = recursivePassword(6,N-1);
            return tmp1 + tmp2;
        } else if (digit == 0) {
            return recursivePassword(7,N-1);
        }
    }

public:
    long countPasswords(int N)
    {      
        long numOfPasswords;

        for (int i = 0; i < 10; i++)
        {
            numOfPasswords = numOfPasswords + recursivePassword(i,N);
        }

        return numOfPasswords;
    }
};
