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
        vector<string> farmcopy = farmland;
        int xElements = farmcopy[0].length();
        int yElements = farmcopy.size();
        int min = 0;
        bool skip = false;
        int dissatisfaction[yElements][xElements];
        int cows = 0;

        //cout << "(Y: "<< yElements << ")(X:" << xElements << ")" << endl;

        for (int i = 0; i < xElements; i++)
        {
            for (int j = 0; j < yElements; j++)
            {
                dissatisfaction[i][j] = 0;
            }
        }


        if(xElements == 1 && yElements == 1)
        {
            skip = true;
            cows = 1;
        } else {

            //Check dissatisfaction of every cow for moo at x,y
            for (int y = 0; y < yElements; y++)
            {
                for (int x = 0; x < xElements; x++)
                {
                    //If no cow, no moo
                    if(farmcopy[y][x] == 'C')
                    {
                        cows++;
                        int sum = 0;
                        for (int j = 0; j < yElements; j++)
                        {
                            for (int i = 0; i < xElements; i++)
                            {
                                //cout << y << " | " << x << " <> " << j << " | " << i << endl;
                                if(( i == x && j == y) || farmcopy[j][i] == '.' )
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
                        if(min == 0)
                        {
                            min = sum;
                        }
                        dissatisfaction[y][x] = sum;

                    } else {
                        //Arbitrarily large value to invalidate the square
                        dissatisfaction[y][x] = 999;
                    }
                    //cout << endl;
                }

            }


        }


        if (skip == false && cows != 1)
        {

            for (int i = 0; i < xElements; i++)
            {
                for (int j = 0; j < yElements; j++)
                {
                    //cout << dissatisfaction[j][i] << " | ";
                    if (dissatisfaction[j][i] < min)
                    {
                        min = dissatisfaction[j][i];
                    }
                }
                //cout << endl;
            }
        }

        return min;
    }
};
