#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
	double money;

 public:
	player();
	player(double createMoney);

	//getters
	double getMoney();

	//setters
	bool setMoney(double newMoney);

	//useful functions
	bool reduceMoney(double reduceMoneyBy);
	bool increaseMoney(double increaseMoneyBy);

	~player();
};

#endif