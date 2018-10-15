#include "item.h"
#include "generic_item.h"
#include "weapon.h"
#include "stall.h"
#include "player.h"
#include "weapon_stall.h"
#include <iostream>
#include <string>
using namespace std;

extern void callHelp();
extern void askTravel();
extern void validLocationList();
extern string lowerCase(string);

//Testing functions
extern void itemOutput(generic_item, generic_item, generic_item, generic_item, generic_item);
extern void weaponOutput(weapon, weapon, weapon, weapon, weapon);

int main ()
{
	string home = "home";
	player player(500);
	stall bakery("Bakery", "bakery", 500);
	weapon_stall forge("Forge", "forge", 500);

	generic_item bread("Rye Bread", 1, 5);
	generic_item bread2("White Bread", 5, 4);
	generic_item donut("Cinnamon Donut", 2, 3);
	generic_item cake("Mud Cake", 3, 8);
	generic_item pie("Apple Pie", 4, 7);

	weapon sword("Short Sword", 5, 1);
	weapon axe("Large Axe", 9, 1);
	weapon mace("Small Mace", 2, 1);
	weapon spear("Long Spear", 7, 1);
	weapon dagger("Small Dagger", 1, 1);

	bakery.setFullItemStock(bread, bread2, donut, pie, cake);
	forge.setFullWeaponStock(sword, axe, mace, spear, dagger);

	string location = home;
	string inputCommand;
	bool moveReady = true;
	bool recentMove = false;
	cout << endl << "Welcome to the Medieval Marketplace." << endl 
	<< "You currently have $" << player.getMoney() << "." << endl 
	<< "Type 'help' if you are lost." << endl;
	askTravel();
	char input[100];

	for (int loop = 1; loop < 10; loop++)
	{

		getline(cin,inputCommand);
		cout << endl;
		inputCommand = lowerCase(inputCommand);

		if(inputCommand == "help")
		{
			callHelp();
		}

		//Go To commands
		if (moveReady == true) 
		{
			if(inputCommand == bakery.getType() && location != bakery.getType())
			{
				location = bakery.getType();
				inputCommand.clear();
				recentMove = true;
				cout << "You're now at the " << location << endl;
			}
			else if(inputCommand == forge.getType() && location != forge.getType())
			{
				location = forge.getType();
				inputCommand.clear();
				recentMove = true;
				cout << "You're now at the " << location << endl;				
			}
			else if(inputCommand == home && location != home) 
			{
				location = home;
				inputCommand.clear();
				cout << "You're now at " << location << "." << endl;
				cout << "You currently have $" << player.getMoney() 
				<< "." << endl;
				askTravel();
				
			}

			//Error Checking
			else if(inputCommand == location)
			{
				if(location != "home")
				{
					cout << "You are already at the " << location << endl;
					recentMove = true;
				}
				else 
				{
					cout << "You are already at " << location << endl;
					askTravel();
				}
			}
			else
			{
				cout << "Invalid input, please enter a valid input:" << endl;
				validLocationList();
			}
		}

		//Movement Tracking
		if (recentMove == true)
		{
			moveReady = false;
		}

		//Market Interactions - NEED TO BE ABLE TO PURCHASE FROM ALL SHOPS !!!!!!!!!!!!!!!!!!!
		if(moveReady == false)
		{
			if(inputCommand == "travel")
			{
				moveReady = true;
				askTravel();
			}
			else 
			{	
				bool knownCommand = false;
				if(location == bakery.getType())
				{	
					for (int i = 0; i < 5; i++)
					{
						if(inputCommand == lowerCase(bakery.getItem(i).getName()))
						{
							cout << "Successfully purchased " << bakery.getItem(i).getName() << "!" << endl << endl;
							player.reduceMoney(bakery.getItem(i).getPrice());
							knownCommand = true;
							break;
						}
					}
					if(knownCommand == false && recentMove == false)
					{
						cout << "Unknown Item/Command, please try again." << endl;
					}

					cout << "What would you like to purchase?			Money: $" 
					<< player.getMoney() << endl;
					bakery.outputItemList();

				}
				else if(location == forge.getType())
				{
					cout << "What would you like to purchase?			Money: $" 
					<< player.getMoney() << endl;
					forge.outputWeaponList();
				}

				cout << endl << "> Travel" << endl << endl;
			}
		}
		
		//Movement Reset
		if (recentMove == true)
		{
			recentMove = false;
		}

		//*IMPORTANT* CONTINUES LOOPING
		loop--;
	}


	return 0;
}