#include <iostream>
#include <string>
using namespace std;

//Below are functions called by the system

void askTravel()
{
	cout << "Where would you like to go? (type in lower case)" 
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
	cout << "Commands:" << endl << endl;

	//location list
	cout << "Locations:" << endl << "> Home" << endl 
	<< "> Bakery" << endl << "> Forge" << endl << endl;
}