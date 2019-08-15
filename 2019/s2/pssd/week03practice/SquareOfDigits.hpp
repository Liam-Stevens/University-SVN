#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SquareOfDigits
{

public:
    int getMax(vector<string> data)
    {
        int cells = 1;
        int xElements = data[0].length();
        int yElements = data.size();

        for (int i = 0; i < yElements; i++)
        {
            for (int j = 0; j < xElements; j++)
            {

            	for (int k = xElements-1; k > j; k--)
            	{
            		if ( data[i][j] == data[i][k] )
            		{
            			int difference = k - j;

            			if (difference+1 <= yElements - i)
            			{
            				//cout << "i: " << i << " j: " << j << " k: " << k << " difference: " << difference << endl;
            				if (data[i][j] == data[i+difference][j] && data[i][j] == data[i+difference][k])
	            			{
	            				if (cells < (difference+1)*(difference+1))
								{
									cells = (difference+1)*(difference+1);
								}
	            			}
            			}
            			
            		}

            	}

            }


        }


        return cells;
    }
};
