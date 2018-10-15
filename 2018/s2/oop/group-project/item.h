#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
protected:
  	int itemID;
  	double price;
  	std::string name;

 public:
	item();

	//getters
	int getId();
	std::string getName();
	double getPrice();

	//setters
	void setName(std::string newName);
	virtual void setPrice(double newPrice) = 0;

	~item();

	//Restructure to have a generic item class and implement pure virtual into parent class into id or price
};

#endif