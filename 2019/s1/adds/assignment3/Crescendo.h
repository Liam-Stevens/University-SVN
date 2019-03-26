#ifndef CRESCENDO_H
#define CRESCENDO_H

#include "computer.h"
#include <string>

class Crescendo : public computer
{
private:
	void generateStrat(int numGames);

public:
	Crescendo();
	Crescendo(int newGames);

	void printTest();
};

#endif