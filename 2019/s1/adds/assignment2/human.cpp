#include "human.h"
#include <string>
#include <iostream>

using namespace std;

human::human(int newGames, string newStrat)
{
	games = newGames;
	bool done = false;
	bool detNum = false;
	int inc = 0;
	while (done == false)
	{
		if (newStrat[inc] == ' ')
		{
			detNum = true;
		}
		newStrat.erase(inc,1);
		if (detNum == true)
		{
			if (inc == games)
			{
				done = true;
			}
			inc++;
		}
	}
	strat = newStrat;
	human::generatePassStrat();
}

int human::getGames()
{
	return games;
}

std::string * human::getStrat()
{
	return passStrat;
}

void human::generatePassStrat()
{
	passStrat = new string[games];
	for (int i = 0; i < games; i ++)
	{
		passStrat[i] = strat[i];
	}
}

human::~human()
{
	//Deleting this pointer causes errors?
	//delete passStrat;
}