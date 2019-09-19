#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FancyFloor
{
public:
    int howmanyBoards(vector<string> layout)
    {      
        int dimensionX = layout[0].length();
        int dimensionY = layout.size();
        int num = 0;

        for (int j = 0; j < dimensionY; j++)
        {
            for (int i = 0; i < dimensionX; i++)
            {
                //cout << "X: " << i << " Y: " << j << endl;
                if (layout[j][i] == '-')
                {
                    //cout << "FOUND: " << i << " " << j << endl;
                    for (int k = i; k < dimensionX; k++)
                    {
                        if (layout[j][k] == '-')
                        {
                            //cout << "SET " << i << " TO " << k << endl;
                            i = k;
                        } else {
                            break;
                        }
                    }
                    
                    num++;
                } else
                {
                    bool skip = false;
                    if (j != 0)
                    {
                        if (layout[j-1][i] != '-')
                        {
                            skip = true;
                            //cout << "SKIPPED" << endl;
                        }
                    }

                    if (skip == false)
                    {
                        //cout << "FOUND: " << i << " " << j << endl;
                        num++;
                    }


                }

            }
        }


        return num;
    }
};
