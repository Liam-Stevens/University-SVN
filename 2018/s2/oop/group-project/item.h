#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{

protected:
  	int itemID;
 	std::string name;
  	double price;

 public:
	item();
	item(std::string createName, int createItemID, double createPrice);

	//getters
	int getId();
	std::string getName();
	double getPrice();

	//setters
	bool setName(std::string newName);
	bool setPrice(double newPrice);

	~item();
};

#endif