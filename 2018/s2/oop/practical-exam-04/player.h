#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"
#include <string>

class player : public person
{
	static int nextID;
	int numberOfGames;
	int *gameTimes;

public:
	player();
	player(std::string n, int sl, int *list, int m);

	int searchGame(int x);
	virtual int get_salary();

};

#endif