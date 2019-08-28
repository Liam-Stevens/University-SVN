#include <iostream>
#include <vector>
using namespace std;

class MonstersValley2
{
private:
    vector<int> freePower;
    vector<int> powerCost;
public:
    int minimumPrice(vector<int> dread, vector<int> price)
    {
        int cost = 0;
        int power = 0;
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
                        float bestPowerCost = 0;
                        int index = 0;
                        for (int j = 0; j < freePower.size(); j++)
                        {
                            if((float)freePower[j]/(float)powerCost[j] > bestPowerCost)
                            {
                                bestPowerCost = (float)freePower[j]/(float)powerCost[j];
                                index = j;
                            }
                        }

                        //cout << "Best Power " << bestPowerCost << endl;

                        if (bestPowerCost > (float)dread[i]/(float)price[i])
                        {
                            //cout << "[1] Price: " << powerCost[index] << " | Power Gained: " << freePower[index] << " | Current Power: " << power << endl;
                            cost = cost + powerCost[index];
                            power = power + freePower[index];
                            powerCost.erase(powerCost.begin()+index);
                            freePower.erase(freePower.begin()+index);
                        } else if (bestPowerCost == (float)dread[i]/(float)price[i]) {

                            if (power + freePower[index] >= dread[i] && powerCost[index] < price[i])
                            {
                                //cout << "[2] Price: " << powerCost[index] << " | Power Gained: " << freePower[index] << " | Current Power: " << power << endl;
                                cost = cost + powerCost[index];
                                power = power + freePower[index];
                                powerCost.erase(powerCost.begin()+index);
                                freePower.erase(freePower.begin()+index);
                            } else {
                                //cout << "[3] Price: " << price[i] << " | Power Gained: " << dread[i] << " | Current Power: " << power << endl;
                                cost = cost + price[i];
                                power = power + dread[i];
                                freePower.clear();
                                powerCost.clear();
                            }

                        } else {
                            //cout << "[4] Price: " << price[i] << " | Power Gained: " << dread[i] << " | Current Power: " << power << endl;
                            cost = cost + price[i];
                            power = power + dread[i];
                            freePower.clear();
                            powerCost.clear();
                        }
                    }

                } else {

                    //cout << "Nothing Avaliable | Price: " << price[i] << " | Power Gained: " << dread[i] << " | Current Power: " << power << endl;
                    cost = cost + price[i];
                    power = power + dread[i];
                }

            } else {
                //cout << "Not Needed | Beat: " << dread[i] << " | Current Power: " << power << endl;
                freePower.push_back(dread[i]);
                powerCost.push_back(price[i]);
            }
        }


        return cost;
    }
};
