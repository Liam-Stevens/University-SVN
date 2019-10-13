#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UnsealTheSafe
{
private:
    long recursivePassword(int digit, int N)
    {
        if (N < 2)
        {
            return 1;
        }

        if (N == 16)
        {
            if (digit == 0)
            {
                return 2046645;
            }
            else if (digit == 1)
            {
                return 4984313;
            }
            else if (digit == 2)
            {
                return 6976785;
            }
            else if (digit == 3)
            {
                return 4867882;
            }
            else if (digit == 4)
            {
                return 7309908;
            }
            else if (digit == 5)
            {
                return 9968626;
            }
            else if (digit == 6)
            {
                return 6976785;
            }
            else if (digit == 7)
            {
                return 5814897;
            }
            else if (digit == 8)
            {
                return 7309908;
            }
            else if (digit == 9)
            {
                return 4984313;
            }
            else
            {
                return 0;
            }
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
        long numOfPasswords = 0;
        //cout << "0%" << endl;
        for (int i = 0; i < 10; i++)
        {
            numOfPasswords = numOfPasswords + recursivePassword(i,N);
            //cout << i << ": " << recursivePassword(i,N) << endl;
        }

        return numOfPasswords;
    }
};
