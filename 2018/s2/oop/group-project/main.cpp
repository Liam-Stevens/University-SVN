#include "item.h"
#include "weapon.h"
#include "stall.h"
#include "player.h"

#include <iostream>
#include <string>
using namespace std;

extern void callHelp();
extern void askTravel();
extern void validLocationList();

int main ()
{
	string home = "home";
	player player(500);
	stall bakery("Bakery", "bakery", 500);
	stall forge("Forge", "forge", 500);
	
	string location = home;
	string inputCommand;
	bool moveReady = true;
	cout << endl << "Welcome to the Medieval Marketplace." << endl 
	<< "You currently have $" << player.getMoney() << "." << endl 
	<< "Type 'help' if you are lost." << endl;
	askTravel();


	for (int loop = 1; loop < 10; loop++)
	{

		cin >> inputCommand;
		cout << endl;

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
				moveReady = false;
				cout << "You're now at the " << location << endl;
			}
			else if(inputCommand == forge.getType() && location != forge.getType())
			{
				location = forge.getType();
				inputCommand.clear();
				moveReady = false;
				cout << "You're now at the " << location << endl;				
			}
			else if(inputCommand == home && location != home) 
			{
				location = home;
				inputCommand.clear();
				moveReady = false;
				cout << "You currently have $" << player.getMoney() 
				<< ". Where would you like to go?" << endl << endl;
				
			}

			//Error Checking
			else if(inputCommand == location)
			{
				cout << "You are already at the " << location << endl;
				moveReady = false;
			}
			else
			{
				cout << "Invalid input, please enter a valid input:" << endl;
				validLocationList();
			}
		}

		//Market Interactions
		if(moveReady == false)
		{
			if(inputCommand == "travel")
			{
				moveReady = true;
				askTravel();
			}
			else 
			{
				if(location == bakery.getType())
				{
					cout << "What would you like to purchase?			Money: " 
					<< player.getMoney() << endl;
				}
				else if(location == forge.getType())
				{
					cout << "What would you like to purchase?			Money: " 
					<< player.getMoney() << endl;
				}

				cout << endl << "> Travel" << endl << endl;
			}
		}
		

		//*IMPORTANT* CONTINUES LOOPING
		loop--;
	}


	return 0;
}