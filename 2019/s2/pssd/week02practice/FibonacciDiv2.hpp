#include <iostream>
#include <cstdlib>
using namespace std;

class FibonacciDiv2
{
    private:
        int fibNum;
    	int* fibArray;

        int calculate(int num, bool newCalc)
        {
        	//Checks if negative number
        	if (num < 0)
        	{
        		return -1;
        	}
        	//Handles creation of fib num storage
        	if (newCalc == true)
        	{
        		fibArray = new int[num+1];

        		//For checking if the array has a value
        		for (int i = 0; i < num+1; i++)
        		{
        			fibArray[i] = -1;
        		}

        		fibNum = 0;
        		fibArray[0] = 0;
        		fibArray[1] = 1;
        		newCalc = false;
        	}

        	//Checks if the fib number exist
        	if (fibArray[num] == -1)
        	{
        		//Handles calculating fib number
        		if (num == 0)
        		{
        			fibNum = fibNum + 0;
        		}
        		else if (num == 1)
        		{
        			fibNum = fibNum + 1;
        		}
        		else
        		{
        			calculate(num-1,false);
        			calculate(num-2,false);
        		}
        		fibArray[num] = fibNum;
        	}
        	else
        	{
        		//If the fib number exists, it will use it
        		fibNum = fibNum + fibArray[num];
        	}


        	return fibNum;
        }

    public:
    int find(int N)
    {
        int steps;
        int bounds[2];
        bounds[0] = 0;

        //Finds the fibinacci bounds around N
        int i = 0;
        while(true)
        {
            int tmp = calculate(i,true);
            if(tmp > N) {
                //Upper Bound
                bounds[1] = tmp;
                break;
            } else {
                //Lower Bound
                bounds[0] = tmp;
            }
            i++;
        }

        //Finds the shortest distance from a bound to N
        steps = abs(bounds[0] - N);
        if(abs(bounds[1] - N) < steps)
        {
            steps = abs(bounds[1] - N);
        }

        /* OLD Workaround
        if(bounds[0] == 0 || bounds[1] == 0) {
            steps = 0;
        } */

        return steps;
    }
};
