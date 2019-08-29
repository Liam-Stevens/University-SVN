#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TimeTravellingCellar
{
public:
    int determineProfit(vector<int> profit, vector<int> decay)
    {
        int margin = 0;

        for (int i = 0; i < profit.size(); i++)
        {
            for (int j = 0; j < decay.size(); j++)
            {
                if (profit[i] - decay[j] > margin && i != j)
                {
                    margin = profit[i] - decay[j];
                }
            }
        }
        
        return margin;
    }
};
