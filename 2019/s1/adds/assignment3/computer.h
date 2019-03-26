#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class computer
{
protected:
	int games;
	std::string *strat;
	std::string type;

	virtual void generateStrat(int numGames);

public:
	computer();
	computer(int newGames);

	int getGames();
	std::string * getStrat();
	std::string getType();

	~computer();
};

#endif