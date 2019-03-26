#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class human
{
protected:
	int games;
	std::string strat;
	std::string *passStrat;

public:
	human(int newGames, std::string newStrat);

	int getGames();
	std::string *getStrat();
	void generatePassStrat();

	~human();
};

#endif