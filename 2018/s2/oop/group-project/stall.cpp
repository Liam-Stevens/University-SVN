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

item stall::getItem(int arrayPosition)
{
	return itemStock[arrayPosition];
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

void stall::setFullItemStock(item item1, item item2, item item3, item item4, item item5)
{
	itemStock[0] = item1;
	itemStock[1] = item2;
	itemStock[2] = item3;
	itemStock[3] = item4;
	itemStock[4] = item5;
}

void stall::setSingleItemStock(int arrayPosition, item item0)
{
	itemStock[arrayPosition] = item0;
}

void stall::outputItemList()
{
	for(int i = 0; i < 5; i++)
	{
		cout << "> " << itemStock[i].getName() << " ($" << itemStock[i].getPrice() << ")" << endl;
	}
}

stall::~stall()
{

}
