#ifndef WEAPONSTALL_H
#define WEAPONSTALL_H

#include "stall.h"
#include "item.h"
#include "weapon.h"
#include <string>

class weapon_stall : public stall
{
	//Array of weapons -  wouldn't recommend changing size as it requires a overhaul of the current system
	weapon weaponStock[5];

public:

	weapon_stall();
	weapon_stall(std::string createName, std::string createShopType, double createMoney);

	//getters
	void outputWeaponList();
	weapon getWeapon(int arrayPosition);

	//setters
	void setFullWeaponStock(weapon weapon1, weapon weapon2, weapon weapon3, weapon weapon4, weapon weapon5);
	void setSingleWeaponStock(int arrayPosition, weapon weapon0);

	~weapon_stall();
};

#endif