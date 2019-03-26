#include "computer.h"
#include "Bureaucrat.h"
#include <string>
#include <iostream>

using namespace std;

Bureaucrat::Bureaucrat()
{
	games = 5;
	type = "Bureaucrat";
	Bureaucrat::generateStrat(5);
}

Bureaucrat::Bureaucrat(int newGames)
{
	games = newGames;
	type = "Bureaucrat";
	Bureaucrat::generateStrat(newGames);
}

void Bureaucrat::generateStrat(int numGames)
{
	strat = new string[numGames];
	for(int i = 0; i < numGames; i++)
	{
		strat[i] = 'P';
	}
}

void Bureaucrat::printTest()
{
	for (int i = 0; i < games; i++)
	{
		cout << strat[i];
	}
	cout << endl;
}