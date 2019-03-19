#include "human.h"
#include <string>

using namespace std;

human::human(int newGames, string newStrat)
{
	games = newGames;
	for (int i = newGames-1; i > 0; i = i-2)
	{
		newStrat.erase(i,1);
	}
	newStrat.erase(0,1);
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