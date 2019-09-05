#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class RGBStreet
{
private:
    int minimumCost;
    vector<int> red;
    vector<int> green;
    vector<int> blue;

    int colourPicker(int lastPick, int house)
    {
        if (house >= red.size())
        {
            return 0;
        }

        if (lastPick == 0)
        {
            int tmp = red[house] + colourPicker(1,1);
            if(tmp < minimumCost)
            {
                minimumCost = tmp;
            }

            tmp = green[house] + colourPicker(2,1);
            if(tmp < minimumCost)
            {
                minimumCost = tmp;
            }
            
            tmp = blue[house] + colourPicker(3,1);
            if(tmp < minimumCost)
            {
                minimumCost = tmp;
            }

            return minimumCost;

        } else {

            int tmp = 0;
            int tmp2 = 0;

            if (lastPick == 1)
            {
                tmp = green[house] + colourPicker(2,house + 1);
                tmp2 = blue[house] + colourPicker(3,house + 1);

            } else if (lastPick == 2)
            {
                tmp = red[house] + colourPicker(1,house + 1);
                tmp2 = blue[house] + colourPicker(3,house + 1);
            } else if (lastPick == 3)
            {
                tmp = green[house] + colourPicker(2,house + 1);
                tmp2 = red[house] + colourPicker(1,house + 1);
            }

            int min = tmp;
            if (min > tmp2)
            {
                min = tmp2;
            }

            return min;

        }

        return minimumCost;
    }

public:
    int estimateCost(vector<string> houses)
    {      
        vector<int> localRed(houses.size(),0);
        vector<int> localGreen(houses.size(),0);
        vector<int> localBlue(houses.size(),0);

        for (int i = 0; i < localRed.size(); i++)
        {
            stringstream(houses[i]) >> localRed[i] >> localGreen[i] >> localBlue[i];
        }

        red = localRed;
        green = localGreen;
        blue = localBlue;

        minimumCost = 1001*20;

        return colourPicker(0,0);
    }
};
