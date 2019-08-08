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
        int sum;

        for (int i = 0; i < elements; i++)
        {
            sum = sum + (bottom*top);
            bottom++;
            top--;
        }

        

        return sum;
    }
};
