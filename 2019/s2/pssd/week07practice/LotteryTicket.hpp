#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LotteryTicket
{
private:
    int bills[4];

    int sumVector(vector<int> picked)
    {
        int sum = 0;
        for (int i = 0; i < picked.size(); i++)
        {
            sum = sum + bills[picked[i]];
        }
        return sum;
    }

    bool contains(int num, vector<int> picked)
    {
        for (int i = 0; i < picked.size(); i++)
        {
            if(num == picked[i])
            {
                return true;
            }
        }
        return false;
    }

    int calculate(int price, vector<int> picked)
    {
        if(sumVector(picked) == price) {
            return 0;
        } else if (sumVector(picked) > price) {
            return 1;
        } else if (picked.size() == 4 && sumVector(picked) != price)
        {
            return 1;
        }

        int tmp[4] = {1,1,1,1};

        picked.push_back(-1);
        if (contains(0,picked) == false)
        {
            picked[picked.size()-1] = 0;
            tmp[0] = calculate(price,picked);
        }

        if (contains(1,picked) == false)
        {
            picked[picked.size()-1] = 1;
            tmp[1] = calculate(price,picked);
        }

        if (contains(2,picked) == false)
        {
            picked[picked.size()-1] = 2;
            tmp[2] = calculate(price,picked);
        }

        if (contains(3,picked) == false)
        {
            picked[picked.size()-1] = 3;
            tmp[3] = calculate(price,picked);
        }

        for (int i = 0; i < 4; i++)
        {
            if (tmp[i] == 0)
            {
                return 0;
            }
        }

        return 1;
    }

public:
    string buy(int price, int b1, int b2, int b3, int b4)
    {
        bills[0] = b1;
        bills[1] = b2;
        bills[2] = b3;
        bills[3] = b4;

        vector<int> choices;
        int results = calculate(price, choices);

        if (results == 0)
        {
            return "POSSIBLE";
        } else {
            return "IMPOSSIBLE";
        }
    }
};
