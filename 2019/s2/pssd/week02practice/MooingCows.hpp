#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class MooingCows
{
    public:
    int dissatisfaction(vector<string> farmland)
    {
        int xElements = farmland[0].length();
        int yElements = farmland.size();
        int min = 0;
        bool skip = false;
        int dissatisfaction[xElements][yElements];
        int cows = 0;

        if(xElements == 1 && yElements == 1)
        {
            skip = true;
            cows = 1;
        } else {

            //Check dissatisfaction of every cow for moo at x,y
            for (int x = 0; x < xElements; x++)
            {
                for (int y = 0; y < yElements; y++)
                {
                    //If no cow, no moo
                    if(farmland[x][y] == 'C')
                    {
                        cows++;
                        int sum = 0;
                        for (int i = 0; i < xElements; i++)
                        {
                            for (int j = 0; j < yElements; j++)
                            {
                                if(( i == x && j == y) || farmland[i][j] == '.' )
                                {
                                    //Cow is not dissatisfied by itself
                                    //cout << "." << " | ";
                                } else {
                                    sum = sum + (pow((x-i),2)+pow((y-j),2));
                                    //cout << (pow((x-i),2)+pow((y-j),2)) << " | ";
                                }
                            }
                            //cout << endl;
                        }
                        dissatisfaction[x][y] = sum;

                    } else {
                        //Arbitrarily large value to invalidate the square
                        dissatisfaction[x][y] = 9999;
                    }
                    //cout << endl;
                }

            }


        }


        if (skip == false && cows != 1)
        {
            min = 9999;

            for (int i = 0; i < xElements; i++)
            {
                for (int j = 0; j < yElements; j++)
                {
                    //cout << dissatisfaction[i][j] << " | ";
                    if (dissatisfaction[i][j] < min)
                    {
                        min = dissatisfaction[i][j];
                    }
                }
                //cout << endl;
            }
        }

        return min;
    }
};
