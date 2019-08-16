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

        int totalSeconds = seconds + 60*minutes + 60*60*hours;
        int displays = 0;

        if (totalSeconds % 100 == 0) {
            displays = 99;
        } else if (totalSeconds % 50 == 0) {
            displays = 49;
        } else if (totalSeconds % 25 == 0) {
            displays = 24;
        } else if (totalSeconds % 20 == 0) {
            displays = 19;
        } else if (totalSeconds % 10 == 0) {
            displays = 9;
        } else if (totalSeconds % 5 == 0) {
            displays = 4;
        } else if (totalSeconds % 4 == 0) {
            displays = 3;
        } else if (totalSeconds % 2 == 0) {
            displays = 1;
        }


        return displays;
    }
};
