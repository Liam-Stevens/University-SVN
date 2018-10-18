#include <iostream>
#include <string>
#include "generic_item.h"
#include "weapon.h"
using namespace std;

//Below are functions called by the system

void askTravel()
{
	cout << "Where would you like to go?" 
	<< endl << "> Home" << endl << "> Bakery" << endl << "> Forge" << endl << endl;
}

void validLocationList()
{
	cout << "> Home" << endl << "> Bakery" << endl << "> Forge" << endl << endl;
}

//Below a functions which should be abled to be called by the user

void callHelp()
{
	//commands
	cout << "Commands:" << endl << "> Help" << endl << endl;

	//location list
	cout << "Locations:" << endl << "> Home" << endl 
	<< "> Bakery" << endl << "> Forge" << endl << endl;
}

string lowerCase(string inputString)
{
	for (int i = 0; i<inputString.length(); i++)
	{
		inputString[i] = tolower(inputString[i]);
	}
	return inputString;
}

void itemOutput(generic_item item1, generic_item item2, generic_item item3, generic_item item4, generic_item item5)
{
	cout << item1.getName() << " " << item2.getPrice() << " " << item3.getPrice() << " " << item4.getPrice() << " " << item5.getPrice() << " " << endl << endl;
}

void weaponOutput(weapon item1, weapon item2, weapon item3, weapon item4, weapon item5)
{
	cout << item1.getPrice() << " " << item2.getPrice() << " " << item3.getPrice() << " " << item4.getPrice() << " " << item5.getPrice() << " " << endl << endl;
}