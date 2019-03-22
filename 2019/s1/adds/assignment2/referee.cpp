#include "referee.h"
#include <string>
#include <iostream>

using namespace std;

referee::referee(std::string * newStrat1, std::string * newStrat2, int newGames)
{
	strat1 = newStrat1;
	strat2 = newStrat2;
	games = newGames;
}

void referee::compare()
{
	results = new char[2*games];
	for (int i = 0; i < games; i++)
	{
		//Check if the strategy is the same
		if (strat1[i] == strat2[i])
		{
			results[2*i] = 'T';
		}
		//Checks if player 1 beat player 2
		else if ((strat1[i] == "R" && strat2[i] == "S") || (strat1[i] == "S" && strat2[i] == "P") || (strat1[i] == "P" && strat2[i] == "R"))
		{
			results[2*i] = 'W';
		}
		//Check if player 2 beat player 1
		else if ((strat1[i] == "R" && strat2[i] == "P") || (strat1[i] == "P" && strat2[i] == "S") || (strat1[i] == "S" && strat2[i] == "R"))
		{
			results[2*i] = 'L';
		}
		//Places a space between each letter
		if(i > 0)
		{
			results[2*i-1] = ' ';
		}
	}
}

void referee::printResults()
{
	//Prints the wins vs losses to the console
	for (int i = 0; i < 2*games; i++)
	{
		cout << char(results[i]);
	}
	cout << endl;
}

referee::~referee()
{
	delete results;
}
