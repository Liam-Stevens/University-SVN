#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VeryInterestingMovie
{
private:


public:
    int maximumPupils(vector<string> seats)
    {
        int spots = 0;

        for (int i = 0; i < seats.size(); i++)
        {

            for (int j = 0; j < seats[i].length(); j++)
            {

                if (seats[i][j] == 'N')
                {
                    //Do Nothing
                }
                else
                {
                    spots++;
                    j++;
                }

            }

        }

        return spots;
    }
};
