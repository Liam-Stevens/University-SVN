#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>
using namespace std;

class ExerciseMachine
{
public:
    int getPercentages(string timer)
    {
        int elements = timer.length();
        int hours = 0;
        int minutes = 0;
        int seconds = 0;
        int switcher = 0;

        //Get total time
        for (int i = 0; i < elements; i++)
        {
            if(isdigit(timer[i]))
            {
                if (switcher == 0) {
                    hours = hours * 10;
                    hours = hours + timer[i] - 48;
                } else if (switcher == 1) {
                    minutes = minutes * 10;
                    minutes = minutes + timer[i] - 48;
                } else {
                    seconds = seconds * 10;
                    seconds = seconds + timer[i] - 48;
                }
            } else {
                switcher++;
            }
        }

        long totalSeconds = seconds + 60*minutes + 60*60*hours;
        cout << totalSeconds << endl;
        double part = (double)totalSeconds/(double)100;
        double whole = part;
        double store = whole;
        cout << part << endl;
        //Get non decimal percentage
        for(int i = 0; i < 100; i++)
        {
            if((double)i*part == (long)i*part)
            {
                whole = i*part;
            }
            cout << i*part << " | " << (long)i*part << endl;
        }
        //Number of time it displays the percentage (removing 100%)
        int displays = (totalSeconds/(int)whole)-1;

        return displays;
    }
};
