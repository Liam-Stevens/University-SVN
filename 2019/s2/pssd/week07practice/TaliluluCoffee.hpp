#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TaliluluCoffee
{
private:
    vector<int> customers;

    int findLow()
    {
        bool foundOne = false;
        bool large = false;
        int min = 999999;
        int index = -1;
        int indexOne = -1;

        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i] > 1 && min > customers[i])
            {
                large = true;
                index = i;
                min = customers[i];
            } else if (customers[i] == 1)
            {
                foundOne = true;
                indexOne = i;
            }
        }

        if (large == false && foundOne == true)
        {
            index = indexOne;
        } else if (large == false && foundOne == false)
        {
            index = 0;
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
    int maxTips(vector<int> tips)
    {
        customers = tips;
        int money = 0;

        for (int i = 0; i < tips.size(); i++)
        {

            int index = findLow();

            money += customers[index];
            customers.erase(customers.begin() + index);

            reduceTips();
        }

        return money;
    }
};
