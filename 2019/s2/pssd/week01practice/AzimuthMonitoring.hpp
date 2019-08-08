#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AzimuthMonitoring
{
    public:
    int getAzimuth(vector<string> instructions)
    {
        //Initialisation
        int elements = instructions.size();
        int angle = 0;

        //Run through list of commands
        for (int i = 0; i < elements; i++)
        {
            //Check command type
            if(instructions[i] == "LEFT") {
                angle = angle - 90;
            } else if(instructions[i] == "RIGHT") {
                angle = angle + 90;
            } else if(instructions[i] == "TURN AROUND") {
                angle = angle + 180;
            } else if(instructions[i] == "HALT") {
                break;
            } else {
                //If the command specifies the degree
                int tmp = 0;
                //Find the number in the command
                for (int j = 0; j < instructions[i].length(); j++)
                {
                    if (isdigit (instructions[i][j]))
                	{
                        //Push the number into a variable
                		tmp = tmp * 10;
                        tmp = tmp + instructions[i][j] - 48;
                	}
                }

                //Check for rotation direction
                if(instructions[i][0] == 'L')
                {
                    angle = angle - tmp;
                } else {
                    angle = angle + tmp;
                }
            }
        }

        //Adjust for absolute rotation
        while(angle < 0)
        {
            angle = angle + 360;
        }
        while(angle >= 360)
        {
            angle = angle - 360;
        }

        return angle;
    }
};
