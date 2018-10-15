#include "item.h"
#include "generic_item.h"
#include <string>
#include <iostream>

using namespace std;

generic_item::generic_item()
{
	itemID = 0;
	name = "unknown";
	price = 0;
}

generic_item::generic_item(string createName, int createItemID, double createPrice)
{
	itemID = createItemID;
	name = createName;
	price = createPrice;
}

void generic_item::setPrice(double newPrice)
{
	if(newPrice >= 0)
	{
		price = newPrice;
	}
	else
	{
		cout << "DEBUG: INVALID PRICE";
	}
}


generic_item::~generic_item()
{

}