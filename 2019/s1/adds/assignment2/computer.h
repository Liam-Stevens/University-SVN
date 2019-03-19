#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class computer
{
protected:
	int games;
	std::string *strat;

public:
	computer(int newGames);

	void generateStrat(int numGames);

	int getGames();
	std::string * getStrat();

	~computer();
};

#endif