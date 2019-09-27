#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TaliluluCoffee
{
private:
    vector<int> customers;

    int findMax()
    {
        int index = -1;
        int max = 0;

        for (int i = 0; i < customers.size(); i++)
        {

            if (max < customers[i])
            {
                max = customers[i];
                index = i;
            }
        }

        return index;
    }

    void reduceTips()
    {
        for (int i = 0; i < customers.size(); i++)
        {
            customers[i]--;
            if (customers[i] < 0)
            {
                customers[i] = 0;
            }
        }
    }

public:
    int maxTip(vector<int> tips)
    {
        customers = tips;
        int money = 0;

        for (int i = 0; i < tips.size(); i++)
        {

            int index = findMax();

            money += customers[index];
            
            customers.erase(customers.begin() + index);

            reduceTips();
        }

        return money;
    }
};
