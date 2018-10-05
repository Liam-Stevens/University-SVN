#ifndef STALL_H
#define STALL_H

#include <string>

class stall
{
  static int count;
  static std::string stallList[5];
  int stallID;
  std::string name;
  std::string shopType;
  double money;
  //Arrays of item, their price and quantity avaliable

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