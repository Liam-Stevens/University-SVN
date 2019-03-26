#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "computer.h"
#include <string>

class Toolbox : public computer
{
private:
	void generateStrat(int numGames);

public:
	Toolbox();
	Toolbox(int newGames);

	void printTest();
};

#endif