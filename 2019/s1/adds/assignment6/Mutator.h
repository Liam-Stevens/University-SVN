#ifndef MUTATOR_H
#define MUTATOR_H

#include "Individual.h"

class Mutator
{
private:


public:
    Mutator();

    virtual Individual mutate(Individual mute, int k);

};

#endif
