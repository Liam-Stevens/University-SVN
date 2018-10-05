#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
	double money;
  	//Array of player inventory

 public:
	player();
	player(double createMoney);

	//getters
	getMoney();

	//setters
	setMoney(double newMoney);

	//useful functions
	reduceMoney(double reduceMoneyBy);
	increaseMoney(double increaseMoneyBy);

	~player();
};

#endif