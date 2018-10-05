#include "player.h"
#include <string>
#include <iostream>

using namespace std;


player::player()
{
	money = 500;
}

player::player(double createMoney)
{
	money = createMoney;
}

//getters
player::getMoney()
{
	return money;
}

//setters
player::setMoney(double newMoney)
{
	money = newMoney;
}

//useful functions
player::reduceMoney(double reduceMoneyBy)
{
	money -= reduceMoneyBy;
}

player::increaseMoney(double increaseMoneyBy)
{
	money += increaseMoneyBy;
}

player::~player()
{

}
