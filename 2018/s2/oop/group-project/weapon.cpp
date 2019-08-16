#include "item.h"
#include "weapon.h"
#include <string>
#include <iostream>

using namespace std;

weapon::weapon()
{	
	name = "?";
	durability = 1;
	size = 5;
	weapon::updatePrice();
	forcePrice = false;
}

weapon::weapon(string createName, double createSize, double createDurability)
{
	name = createName;
	size = createSize;
	durability = createDurability;
	weapon::updatePrice();
	forcePrice = false;
}

//getters
double weapon::getSize()
{
	return size;
}

double weapon::getDurability()
{
	return durability;
}

string weapon::getName()
{
	return name;
}

//setters
void weapon::setSize(double newSize)
{
	size = newSize;
	weapon::updatePrice();
}

void weapon::setDurability(double newDurability)
{
	durability = newDurability;
	weapon::updatePrice();
}

void weapon::updatePrice()
{
	price = durability*size*10;
}

void weapon::setPrice(double newPrice)
{
	price = newPrice;
	forcePrice = true;
	if(newPrice < 0)
	{
		forcePrice = false;
		weapon::updatePrice();
	}
}

weapon::~weapon()
{

}