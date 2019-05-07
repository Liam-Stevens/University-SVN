#include "Individual.h"
#include "Mutator.h"
#include "BitFlip.h"


Individual BitFlip::mutate(Individual mute, int k)
{
    bool wrap = true;
    //Checks how far the number will wrap around the string
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

    //Flips the bit
    mute.flipBit(k-1);
    return mute;
}
