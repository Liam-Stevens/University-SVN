#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

class DownloadingFiles
{
    public:
    double actualTime(vector<string> tasks)
    {
        //Find number of elements in array
        int elements = tasks.size();
        int speeds[elements];
        int times[elements];

        //Retrieves Time and Speed from string array
        for (int i = 0; i < elements; i++)
        {
            //Storage for time and speed ints
            bool speed = true;
            speeds[i] = 0;
            times[i] = 0;

            for (int j = 0; j < tasks[i].length(); j++)
            {
                if(speed == true) {
                    if (isdigit (tasks[i][j]))
            		{
                        //push the number into the array
            			speeds[i] = speeds[i] * 10;
                        speeds[i] = speeds[i] + tasks[i][j] - 48;
            		}
            		else
            		{
                        //change tracking of speed to time
            			speed = false;
            		}
                } else {
                    if (isdigit (tasks[i][j]))
            		{
                        //push the number into the array
            			times[i] = times[i] * 10;
                        times[i] = times[i] + tasks[i][j] - 48;
            		}
                }
            }
        }

        double totalSize = 0;
        double totalBandwidth = 0;

        //Adds each elements to the total
        for(int i = 0; i < elements; i++)
        {
            totalBandwidth = totalBandwidth + (double)speeds[i];
            totalSize = totalSize + (double)(speeds[i]*times[i]);
        }

        //Final Calculation
        double finishTime = totalSize/totalBandwidth;

        return finishTime;
    }
};
