#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class ElevatorLimit
{
public:
    vector<int> getRange(vector<int> enter, vector<int> exiter, int physicalLimit)
    {
        int elements = enter.size();
        int riders = 0;
        int minRiders = 0;
        int maxRiders = 0;
        bool valid = true;

        for (int i = 0; i < elements; i++)
        {
            riders = riders - exiter[i];

            if ( abs(riders) > physicalLimit)
            {
                valid = false;
                break;
            }
            if (riders > maxRiders)
            {
                maxRiders = riders;
            }
            if (riders < minRiders)
            {
                minRiders = riders;
            }

            riders = riders + enter[i];
            //cout << riders << " [] " << enter[i] << " [] " << exiter[i] << endl;
            if ( abs(riders) > physicalLimit)
            {
                valid = false;
                break;
            }
            if (riders > maxRiders)
            {
                maxRiders = riders;
            }
            if (riders < minRiders)
            {
                minRiders = riders;
            }

        }

        //cout << endl << minRiders << " > " << maxRiders << endl;

        vector<int> start;

        if (valid == true)
        {
            start.push_back( abs(minRiders));

            start.push_back(physicalLimit-maxRiders);
        }

        return start;
    }
};
