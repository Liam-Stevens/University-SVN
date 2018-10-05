#ifndef STALL_H
#define STALL_H

#include <string>

class stall
{
  static int count;
  int stallID;
  std::string name;
  std::string shopType
  double money;
  //Arrays of item, their price and quantity avaliable

 public:
	stall();
	stall(std::string createName, std::string createShopType, double createMoney);

	//getters
	getName();
	getType();
	getMoney();

	//setters
	setName(std::string newName);
	setType(std::string newType);
	setMoney(double newMoney);

	//usable functions
	reduceMoney(double reduceMoneyBy);
	increaseMoney(double increaseMoneyBy);

	//Need functions for adjusting shop stock

	~stall();
};

#endif