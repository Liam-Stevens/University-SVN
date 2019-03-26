#ifndef PAPERDOLL_H
#define PAPERDOLL_H

#include "computer.h"
#include <string>

class PaperDoll : public computer
{
private:
	void generateStrat(int numGames);

public:
	PaperDoll();
	PaperDoll(int newGames);

	void printTest();
};

#endif