#ifndef MUTATOR_H
#define MUTATOR_H

#include "Individual.h"

class Mutator
{
private:


public:

    virtual Individual mutate(Individual mute, int k) = 0;

};

#endif
