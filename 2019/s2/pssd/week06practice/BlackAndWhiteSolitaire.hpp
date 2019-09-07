#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BlackAndWhiteSolitaire
{
public:
    int minimumTurns(string cardFront)
    {
        int difference1 = 0;
        int difference2 = 0;
        bool order = false;

        for(int i = 0; i < cardFront.length(); i++)
        {

            if(order == false)
            {
                if (cardFront[i] == 'W')
                {
                    difference2++;
                } else if (cardFront[i] == 'B')
                {
                    difference1++;
                }
                order = true;
            } else {
                if (cardFront[i] == 'B')
                {
                    difference2++;
                } else if (cardFront[i] == 'W')
                {
                    difference1++;
                }
                order = false;
            }
        }

        int num = difference1;
        if (difference2 < num)
        {
            num = difference2;
        }

        return num;
    }
};
