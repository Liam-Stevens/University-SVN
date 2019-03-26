#include "computer.h"
#include "Avalanche.h"
#include <string>
#include <iostream>

using namespace std;

Avalanche::Avalanche()
{
	games = 5;
	type = "Avalanche";
	Avalanche::generateStrat(5);
}

Avalanche::Avalanche(int newGames)
{
	games = newGames;
	type = "Avalanche";
	Avalanche::generateStrat(newGames);
}

void Avalanche::generateStrat(int numGames)
{
	strat = new string[numGames];
	for(int i = 0; i < numGames; i++)
	{
		strat[i] = 'R';
	}
}

void Avalanche::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}