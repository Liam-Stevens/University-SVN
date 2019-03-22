#ifndef REFEREE_H
#define REFEREE_H

#include <string>

class referee
{
protected:
	std::string * strat1;
	std::string * strat2;
	int games;
	std::string results;

public:
	
	referee(std::string * newStrat1, std::string * newStrat2, int newGames);

	void compare();
	void printResults();

	~referee();
};

#endif