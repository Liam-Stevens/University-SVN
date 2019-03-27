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

	//Fills array with scissors
	for(int i = 0; i < numGames; i++)
	{
		strat[i] = 'S';
	}
}

//Debug test
void Toolbox::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}