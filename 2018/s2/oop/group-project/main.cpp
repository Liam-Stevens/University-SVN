#include "stall.h"
#include "player.h"

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	player player(500); //amount of money is wrong, send help. (This should be fixed now)

	string location = "home";
	string newLocation;
	cout << "Welcome to the Medieval Marketplace" << endl << "You currently have $" << player.getMoney() << ". Where would you like to go?" << endl;
	cin >> newLocation;
	//check if newLocation is a store, if not, throw back an error and dont move, if so, newLocation = location
	//e.g. (but use array (when we have one) with a for loop at the top) {The location system can be coded as a parent of the stall class}
	if (newLocation == "bakery") {
		location = "bakery";
		newLocation.clear();
		cout << "You're now at the " << location << endl << "What would you like to purchase?			MONEY = " << player.getMoney() << endl;
	} else if (newLocation == "home" && location != "home") {
		location = "home";
		newLocation.clear();
		cout << "You currently have $" << player.getMoney() << ". Where would you like to go?" << endl;
	}


	return 0;
}