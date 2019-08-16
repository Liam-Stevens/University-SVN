#ifndef STALL_H
#define STALL_H

#include "item.h"
#include "generic_item.h"
#include "weapon.h"
#include <string>

class stall
{
protected:
  static int count;
  int stallID;
  std::string name;
  std::string shopType;
  double money;
  generic_item itemStock[5];

 public:
	stall();
	stall(std::string createName, std::string createShopType, double createMoney);

	//getters
	int getId();
	std::string getName();
	std::string getType();
	double getMoney();
	generic_item getItem(int arrayPosition);

	//setters
	bool setName(std::string newName);
	bool setType(std::string newType);
	bool setMoney(double newMoney);

	//usable functions
	bool reduceMoney(double reduceMoneyBy);
	bool increaseMoney(double increaseMoneyBy);
	void setFullItemStock(generic_item item1, generic_item item2, generic_item item3, generic_item item4, generic_item item5);
	void setSingleItemStock(int arrayPosition, generic_item item0);
	void outputItemList();

	~stall();
};

#endif