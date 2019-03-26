#ifndef FISTFULLODOLLARS_H
#define FISTFULLODOLLARS_H

#include "computer.h"
#include <string>

class FistfullODollars : public computer
{
private:
	void generateStrat(int numGames);

public:
	FistfullODollars();
	FistfullODollars(int newGames);

	void printTest();
};

#endif