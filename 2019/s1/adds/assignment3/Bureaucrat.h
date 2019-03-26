#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "computer.h"
#include <string>

class Bureaucrat : public computer
{
private:
	void generateStrat(int numGames);

public:
	Bureaucrat();
	Bureaucrat(int newGames);

	void printTest();
};

#endif