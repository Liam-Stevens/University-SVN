#include "stall.h"
#include "item.h"
#include "weapon.h"
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
int stall::getId()
{
	return stallID;
}

string stall::getName()
{
	return name;
}

string stall::getType()
{
	return shopType;
}

double stall::getMoney()
{
	return money;
}


//setters
bool stall::setName(std::string newName)
{
	name = newName;
	return true;
}

bool stall::setType(std::string newType)
{
	shopType = newType;
	return true;
}

bool stall::setMoney(double newMoney)
{
	money = newMoney;
	return true;
}

bool stall::reduceMoney(double reduceMoneyBy)
{
	money -= reduceMoneyBy;
	return true;
}

bool stall::increaseMoney(double increaseMoneyBy)
{
	money += increaseMoneyBy;
	return true;
}

stall::~stall()
{

}
