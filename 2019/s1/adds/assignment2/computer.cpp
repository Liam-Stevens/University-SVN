#include "computer.h"
#include <string>

using namespace std;

computer::computer(int newGames)
{
	games = newGames;
	computer::generateStrat(newGames);
}

//Makes a dynamic string array filled with R for how many games are played
void computer::generateStrat(int numGames)
{
	strat = new string[numGames];
	for(int i = 0; i < numGames; i++)
	{
		strat[i] = 'R';
	}
}

int computer::getGames()
{
	return games;
}

std::string * computer::getStrat()
{
	return strat;
}

computer::~computer()
{	
	//Also causes an error when cleared
	//delete strat;
}