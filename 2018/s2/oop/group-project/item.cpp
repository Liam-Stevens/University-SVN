#include "item.h"
#include <string>
#include <iostream>

using namespace std;

item::item()
{
	itemID = 0;
	name = "unknown";
	price = 0;
}

item::item(string createName, int createItemID, double createPrice)
{
	itemID = createItemID;
	name = createName;
	price = createPrice;
}

//getters
int item::getId()
{
	return itemID;
}

string item::getName()
{
	return name;
}

double item::getPrice()
{
	return price;
}


//setters
bool item::setName(string newName)
{
	name = newName;
}

bool item::setPrice(double newPrice)
{
	price = newPrice;
}

item::~item()
{

}