#include "player.h"
#include <string>
#include <iostream>

using namespace std;


player::player()
{
	money = 00;
}

player::player(double createMoney)
{
	money = createMoney;
}

//getters
double player::getMoney()
{
	return money;
}

//setters
bool player::setMoney(double newMoney)
{
	money = newMoney;
	return true;
}

//useful functions
bool player::reduceMoney(double reduceMoneyBy)
{
	money -= reduceMoneyBy;
	return true;
}

bool player::increaseMoney(double increaseMoneyBy)
{
	money += increaseMoneyBy;
	return true;
}

player::~player()
{

}
