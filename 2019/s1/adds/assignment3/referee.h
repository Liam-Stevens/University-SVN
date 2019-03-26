#ifndef REFEREE_H
#define REFEREE_H

#include <string>

class referee
{
private:
	std::string * strat1;
	std::string * strat2;
	int games;
	std::string results;

public:
	referee();
	referee(std::string * newStrat1, std::string * newStrat2, int newGames);

	void setCompetitors(std::string * newStrat1, std::string * newStrat2);
	void compare();
	void printResults();
	std::string getResults();
};

#endif