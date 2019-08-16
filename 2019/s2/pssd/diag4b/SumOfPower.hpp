#include <vector>
using namespace std;

class SumOfPower
{
    public:
    int findSum(vector<int> array)
    {
        int elements = array.size();
        int bottom = 1;
        int top = elements;
        int sum = 0;

        for (int i = 0; i < elements; i++)
        {
            for (int j = i; j < elements; j++)
            {
                sum = sum + array[j];
            }

        }

        

        return sum;
    }
};
