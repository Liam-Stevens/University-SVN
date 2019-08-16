#include <iostream>
#include <string>
using namespace std;

class StreetParking
{

public:
    int freeParks(string street)
    {
        int parks = 0;
        int elements = street.length();

        for (int i = 0; i < elements; i++)
        {
            if (street[i] == 'B')
            {
                if(i - 1 >= 0)
                {
                    street[i-1] = 'Z';
                }
                if(i - 2 >= 0)
                {
                    street[i-2] = 'Z';
                }
            }

            if (street[i] == 'S')
            {
                if(i - 1 >= 0)
                {
                    street[i-1] = 'Z';
                }
                if(i + 1 < elements)
                {
                    if(street[i+1] != 'B' && street[i+1] != 'S')
                    {
                        street[i+1] = 'Z';
                    }
                }
            }
        }

        for (int i = 0; i < elements; i++)
        {
            if(street[i] == '-')
            {
                parks++;
            }
        }


        return parks;
    }
};
