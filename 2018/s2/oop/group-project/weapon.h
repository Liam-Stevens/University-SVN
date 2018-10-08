#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include <string>

class weapon : public item
{
  double durability;
  double size;
  double price;

 public:
	weapon();
	weapon(std::string createName, double createSize, double createDurability);

	//getters
	double getSize();
	double getDurability();
	double getPrice();

	//setters
	void setSize(double newSize);
	void setDurability(double newDurability);

	//useful functions
	void updatePrice();

	~weapon();
};

#endif