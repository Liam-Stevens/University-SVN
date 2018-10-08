#include "item.h"
#include "weapon.h"
#include "stall.h"
#include "player.h"

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string home = "home";
	player player(500);
	stall bakery("Bakery", "bakery", 500);
	stall forge("Forge", "forge", 500);
	
	string location = home;
	string inputCommand;
	cout << endl << "Welcome to the Medieval Marketplace." << endl << "You currently have $" << player.getMoney() << "." << endl << "Type help if you are lost." << endl << "Where would you like to go? (type in lower case)" << endl << "> Home" << endl << "> Bakery" << endl << "> Forge" << endl << endl;


	for (int loop = 1; loop < 10; loop++)
	{

		cin >> inputCommand;
		cout << endl;
		//check if inputCommand is a store, if not, throw back an error and dont move, if so, inputCommand = location
		//e.g. (but use array (when we have one) with a for loop at the top) {The location system can be coded as a parent of the stall class}
		if(inputCommand == bakery.getType() && location != bakery.getType()){
			location = bakery.getType();
			inputCommand.clear();
			cout << "You're now at the " << location << endl << "What would you like to purchase?			MONEY = " << player.getMoney() << endl << endl;
		}
		else if(inputCommand == forge.getType() && location != forge.getType()){
			location = forge.getType();
			inputCommand.clear();
			cout << "You're now at the " << location << endl << "What would you like to purchase?			MONEY = " << player.getMoney() << endl << endl;
			
		}
		else if(inputCommand == home && location != home) {
			location = home;
			inputCommand.clear();
			cout << "You currently have $" << player.getMoney() << ". Where would you like to go?" << endl << endl;
			
		}
		else if(inputCommand == location)
		{
			cout << "You are already at the " << location << endl << endl;
			
		}
		else if(inputCommand == "help")
		{
			//commands
			cout << "Commands:" << endl << endl;

			//location list
			cout << "Locations:" << endl << "> Home" << endl << "> Bakery" << endl << "> Forge" << endl << endl;	
		}
		else
		{
			cout << "Invalid input, please enter a valid input:" << endl << "> Home" << endl << "> Bakery" << endl << "> Forge" << endl << endl;
		}

		loop--;
	}


	return 0;
}

