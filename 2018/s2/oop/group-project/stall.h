#ifndef STALL_H
#define STALL_H

#include "item.h"
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
  item itemStock[5];

 public:
	stall();
	stall(std::string createName, std::string createShopType, double createMoney);

	//getters
	int getId();
	std::string getName();
	std::string getType();
	double getMoney();

	//setters
	bool setName(std::string newName);
	bool setType(std::string newType);
	bool setMoney(double newMoney);

	//usable functions
	bool reduceMoney(double reduceMoneyBy);
	bool increaseMoney(double increaseMoneyBy);

	//Need functions for adjusting shop stock

	~stall();
};

#endif