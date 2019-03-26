#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H

#include "computer.h"
#include <string>

class RandomComputer : public computer
{
private:
	void generateStrat(int numGames);

public:
	RandomComputer();
	RandomComputer(int newGames);

	void printTest();
};

#endif