#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Thimbles
{
private:
    vector<int> swap1;
    vector<int> swap2;
    int ballLocation;

    void extractNumbers(vector<string> input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            swap1.push_back(input[i][0] - 48);
            swap2.push_back(input[i][2] - 48);
        }
    }

    void swapCups(int first, int second)
    {
        if (first == second)
        {
            return;
        } else if (ballLocation == first)
        {
            ballLocation = second;
        } else if (ballLocation == second)
        {
            ballLocation = first;
        }
    }

public:
    int thimbleWithBall(vector<string> swaps)
    {
        swap1.clear();
        swap2.clear();
        ballLocation = 1;

        extractNumbers(swaps);

        for (int i = 0; i < swaps.size(); i++)
        {
            swapCups(swap1[i],swap2[i]);
        }


        return ballLocation;
    }
};
