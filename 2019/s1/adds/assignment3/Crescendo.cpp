#include "computer.h"
#include "Crescendo.h"
#include <string>
#include <iostream>

using namespace std;

Crescendo::Crescendo()
{
	games = 5;
	type = "Crescendo";
	Crescendo::generateStrat(5);
}

Crescendo::Crescendo(int newGames)
{
	games = newGames;
	type = "Crescendo";
	Crescendo::generateStrat(newGames);
}

void Crescendo::generateStrat(int numGames)
{
	strat = new string[numGames];
	string reference[3] = {"P","S","R"};
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
void Crescendo::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}