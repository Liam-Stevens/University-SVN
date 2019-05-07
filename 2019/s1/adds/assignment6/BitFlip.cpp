#include "Individual.h"
#include "BitFlip.h"

BitFlip::BitFlip()
{

}

Individual BitFlip::mutate(Individual mute, int k)
{
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

    mute.flipBit(k-1);
    return mute;
}
