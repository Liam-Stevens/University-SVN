#include "computer.h"
#include "RandomComputer.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

RandomComputer::RandomComputer()
{
	games = 5;
	type = "RandomComputer";
	RandomComputer::generateStrat(5);
}

RandomComputer::RandomComputer(int newGames)
{
	games = newGames;
	type = "RandomComputer";
	RandomComputer::generateStrat(newGames);
}

void RandomComputer::generateStrat(int numGames)
{
	strat = new string[numGames];

	//Fills the Strat array with at random
	for(int i = 0; i < numGames; i++)
	{
		int dice = rand() % 3;
		cout << dice << endl;
		if (dice == 0)
		{
			strat[i] = 'R';
		}
		else if (dice == 1)
		{
			strat[i] = 'P';
		}
		else if (dice == 2)
		{
			strat[i] = 'S';
		}
	}
}

//Debug test
void RandomComputer::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}