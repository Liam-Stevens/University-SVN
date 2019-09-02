#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Truckloads
{
public:
    int numTrucks(int numCrates, int loadSize)
    {
        if (numCrates <= loadSize)
        {
            return 1;
        }
        return numTrucks(numCrates/2,loadSize) + numTrucks(numCrates/2 + numCrates%2,loadSize);
    }
};
