#include <vector>
#include <iostream>
using namespace std;

class Ascending
{
    public:
    int steps(vector<int> flights, int stairsPerStride)
    {
    	int elements = flights.size();
    	int strides = 0;

    	for (int i = 0; i < elements; i++)
    	{
    		strides = strides + (flights[i] / stairsPerStride);
    		if (flights[i] % stairsPerStride != 0)
    		{
    			strides++;
    		}

    		if(i != elements - 1)
    		{
    			strides = strides + 2;
    		}
    	}
        

        return strides;
    }
};
