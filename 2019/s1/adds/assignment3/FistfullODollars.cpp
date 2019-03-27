#include "computer.h"
#include "FistfullODollars.h"
#include <string>
#include <iostream>

using namespace std;

FistfullODollars::FistfullODollars()
{
	games = 5;
	type = "FistfullODollars";
	FistfullODollars::generateStrat(5);
}

FistfullODollars::FistfullODollars(int newGames)
{
	games = newGames;
	type = "FistfullODollars";
	FistfullODollars::generateStrat(newGames);
}

void FistfullODollars::generateStrat(int numGames)
{
	strat = new string[numGames];
	string reference[3] = {"R","P","P"};
	int counter = 0;

	//Loops through reference array to fill strat
	for(int i = 0; i < numGames; i++)
	{	
		if (counter >= 3)
		{
			counter = 0;
		}
		strat[i] = reference[counter];
		counter++;
	}
}

//Debug tests
void FistfullODollars::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}