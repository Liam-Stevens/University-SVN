#include "item.h"
#include "weapon.h"
#include <string>
#include <iostream>

using namespace std;

weapon::weapon()
{
	durability = 1;
	size = 5;
	weapon::updatePrice();
}

weapon::weapon(string createName, double createSize, double createDurability)
{
	name = createName;
	size = createSize;
	durability = createDurability;
	weapon::updatePrice();
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

double weapon::getPrice()
{
	return price;
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

weapon::~weapon()
{

}