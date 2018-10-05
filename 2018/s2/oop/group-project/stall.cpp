#include "stall.h"
#include <string>
#include <iostream>

using namespace std;

int stall::count = 0;


stall::stall()
{	
	stallID = count;
	count++;
	name = "NAME";
  	shopType = "SHOPTYPE";
  	money = 500;
}

stall::stall(std::string createName, std::string createShopType, double createMoney)
{
	stallID = count;
	count++;
	name = createName;
  	shopType = createShopType;
  	money = createMoney;
}


//getters
stall::getName()
{
	return name;
}

stall::getType()
{
	return shopType;
}

stall::getMoney()
{
	return money;
}


//setters
stall::setName(std::string newName)
{
	name = newName;
}

stall::setType(std::string newType)
{
	shopType = newType;
}

stall::setMoney(double newMoney)
{
	money = newMoney
}

stall::reduceMoney(double reduceMoneyBy)
{
	money -= reduceMoneyBy;
}

stall::increaseMoney(double increaseMoneyBy)
{
	money += increaseMoneyBy;
}

stall::~stall()
{

}
