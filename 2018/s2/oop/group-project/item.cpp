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
void item::setName(string newName)
{
	name = newName;
}

item::~item()
{

}