#include "computer.h"
#include "Toolbox.h"
#include <string>
#include <iostream>

using namespace std;

Toolbox::Toolbox()
{
	games = 5;
	type = "Toolbox";
	Toolbox::generateStrat(5);
}

Toolbox::Toolbox(int newGames)
{
	games = newGames;
	type = "Toolbox";
	Toolbox::generateStrat(newGames);
}

void Toolbox::generateStrat(int numGames)
{
	strat = new string[numGames];
	for(int i = 0; i < numGames; i++)
	{
		strat[i] = 'S';
	}
}

void Toolbox::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}