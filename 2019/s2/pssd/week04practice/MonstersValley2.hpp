#include <iostream>
#include <vector>
using namespace std;

class MonstersValley2
{
private:
    vector<long> freePower;
    vector<long> powerCost;
public:
    int minimumPrice(vector<int> dread, vector<int> price)
    {
        long cost = 0;
        long power = 0;
        freePower.clear();
        powerCost.clear();

        if(dread.size() == 1 && dread[0] > 0)
        {
            cost = price[0];
            return cost;
        }

        for (int i = 0; i < dread.size(); i++)
        {
            if(power < dread[i]) {

                if(freePower.size() != 0)
                {
                    while(power < dread[i])
                    {
                        long double bestPowerCost = 0;
                        long index = 0;
                        for (int j = 0; j < freePower.size(); j++)
                        {
                            if((long double)freePower[j]/(long double)powerCost[j] > bestPowerCost)
                            {
                                bestPowerCost = (long double)freePower[j]/(long double)powerCost[j];
                                index = j;
                            }
                        }

                        //cout << "Best Power " << bestPowerCost << endl;

                        if (bestPowerCost > (long double)dread[i]/(long double)price[i])
                        {
                            cout << "[1] Price: " << powerCost[index] << " | Power Gained: " << freePower[index] << " | Current Power: " << power << endl;
                            cost = cost + powerCost[index];
                            power = power + freePower[index];
                            powerCost.erase(powerCost.begin()+index);
                            freePower.erase(freePower.begin()+index);
                        } else if (power + freePower[index] >= dread[i] && powerCost[index] < price[i])
                        {
                            cout << "[2] Price: " << powerCost[index] << " | Power Gained: " << freePower[index] << " | Current Power: " << power << endl;
                            cost = cost + powerCost[index];
                            power = power + freePower[index];
                            powerCost.erase(powerCost.begin()+index);
                            freePower.erase(freePower.begin()+index);
                        } else {
                            cout << "[3] Price: " << price[i] << " | Power Gained: " << dread[i] << " | Current Power: " << power << endl;
                            cost = cost + price[i];
                            power = power + dread[i];
                            //freePower.clear();
                            //powerCost.clear();
                        }
                    }

                } else {

                    cout << "Nothing Avaliable | Price: " << price[i] << " | Power Gained: " << dread[i] << " | Current Power: " << power << endl;
                    cost = cost + price[i];
                    power = power + dread[i];
                }

            } else {
                cout << "Not Needed | Beat: " << dread[i] << " | Current Power: " << power << endl;
                freePower.push_back(dread[i]);
                powerCost.push_back(price[i]);
            }
        }


        return cost;
    }
};
