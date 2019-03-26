#ifndef AVALANCHE_H
#define AVALANCHE_H

#include "computer.h"
#include <string>

class Avalanche : public computer
{
private:
	void generateStrat(int numGames);

public:
	Avalanche();
	Avalanche(int newGames);

	void printTest();
};

#endif