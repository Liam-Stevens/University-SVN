#include "referee.h"
#include <string>
#include <iostream>

using namespace std;

referee::referee()
{
	games = 5;
}

referee::referee(std::string * newStrat1, std::string * newStrat2, int newGames)
{
	strat1 = newStrat1;
	strat2 = newStrat2;
	games = newGames;
}

void referee::setCompetitors(std::string * newStrat1, std::string * newStrat2)
{
	strat1 = newStrat1;
	strat2 = newStrat2;
}

void referee::compare()
{
	if (results.length() > 0)
	{
		results = "";
	}
	for (int i = 0; i < games; i++)
	{
		//Check if the strategy is the same
		if (strat1[i] == strat2[i])
		{
			results.push_back('T');
		}
		//Checks if player 1 beat player 2
		else if ((strat1[i] == "R" && strat2[i] == "S") || (strat1[i] == "S" && strat2[i] == "P") || (strat1[i] == "P" && strat2[i] == "R"))
		{
			results.push_back('W');
		}
		//Check if player 2 beat player 1
		else if ((strat1[i] == "R" && strat2[i] == "P") || (strat1[i] == "P" && strat2[i] == "S") || (strat1[i] == "S" && strat2[i] == "R"))
		{
			results.push_back('L');
		}
	}

}

void referee::printResults()
{
	//Prints the wins vs losses to the console
	for (int i = 0; i < games; i++)
	{
		cout << results[i];
	}
	cout << endl;
}

string referee::getResults()
{
	return results;
}