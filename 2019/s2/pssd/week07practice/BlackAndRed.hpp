#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BlackAndRed
{
private:
    bool testDeck(int cutLocation, string deck)
    {
        int reds = 0;
        int blacks = 0;

        for (int j = 0; j < deck.length(); j++)
        {
            int loc = j + cutLocation;
            if (loc > deck.length())
            {
                loc = loc - (deck.length() + 1);
            }

            if(deck[loc] == 'R')
            {
                reds++;
            } else if (deck[loc] == 'B')
            {
                blacks++;
            }

            //cout << deck[loc];

            if (reds > blacks)
            {
                //cout << endl;
                return false;
            }

        }
        //cout << endl;
        return true;

    }

public:
    int cut(string deck)
    {

        for (int i = 0; i < deck.length(); i++)
        {
            if (testDeck(i,deck))
            {
                return i;
            } else {
                //cout << "Failed: " << i << endl;
            }
        }

        return -1;
    }
};
