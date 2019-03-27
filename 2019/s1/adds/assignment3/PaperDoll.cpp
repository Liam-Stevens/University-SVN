#include "computer.h"
#include "PaperDoll.h"
#include <string>
#include <iostream>

using namespace std;

PaperDoll::PaperDoll()
{
	games = 5;
	type = "PaperDoll";
	PaperDoll::generateStrat(5);
}

PaperDoll::PaperDoll(int newGames)
{
	games = newGames;
	type = "PaperDoll";
	PaperDoll::generateStrat(newGames);
}

void PaperDoll::generateStrat(int numGames)
{
	strat = new string[numGames];
	string reference[3] = {"P","S","S"};
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
void PaperDoll::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}