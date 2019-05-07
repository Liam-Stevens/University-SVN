#include "Individual.h"
#include "Mutator.h"
#include "Rearrange.h"
#include <string>

using namespace std;

Individual Rearrange::mutate(Individual mute, int k)
{
    //Checks how far the number wraps around the string
    bool wrap = true;
    while (wrap == true)
    {
        if (k > mute.getLength())
        {
            k = k - mute.getLength();
        }
        else
        {
            wrap = false;
        }
    }

    //Rearranges the string
    string binaryRe = mute.getString();
    string temp (mute.getLength(), 'x');
    //Grabs string from k and inserts into new string
    for (int i = (k-1); i < mute.getLength(); i++)
    {
        temp[i - (k - 1)] = binaryRe[i];
    }
    //Grabs string from start to k and inserts at the end of new string
    for (int i = 0; i < (k - 1); i++)
    {
        temp[i + mute.getLength() - (k - 1)] = binaryRe[i];
    }
    mute.setString(temp);

    return mute;
}
