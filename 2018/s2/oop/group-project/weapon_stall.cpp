#include "stall.h"
#include "item.h"
#include "weapon.h"
#include "weapon_stall.h"
#include <string>
#include <iostream>

using namespace std;

weapon_stall::weapon_stall()
{	
	stallID = count;
	count++;
	name = "NAME";
  	shopType = "SHOPTYPE";
  	money = 500;
}

weapon_stall::weapon_stall(std::string createName, std::string createShopType, double createMoney)
{
	stallID = count;
	count++;
	name = createName;
  	shopType = createShopType;
  	money = createMoney;
}

void weapon_stall::setFullWeaponStock(weapon weapon1, weapon weapon2, weapon weapon3, weapon weapon4, weapon weapon5)
{
	//Only goes to five because the array is of size 5
	weaponStock[0] = weapon1;
	weaponStock[1] = weapon2;
	weaponStock[2] = weapon3;
	weaponStock[3] = weapon4;
	weaponStock[4] = weapon5;
}

void weapon_stall::setSingleWeaponStock(int arrayPosition, weapon weapon0)
{
	weaponStock[arrayPosition] = weapon0;
}

weapon_stall::~weapon_stall()
{

}