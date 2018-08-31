#include <string>
#include "person.h"
#include "aircraft.h"
#include <iostream>

using namespace std;

int aircraft::count2 = 0;


aircraft::aircraft()
{
	id2 = count2;
	count2++;
	sign = "?";
}

aircraft::aircraft(string callsign,person thePilot,person theCoPilot)
{
	sign = callsign;
	inCraft[0] = thePilot;
	inCraft[1] = theCoPilot;
}

void aircraft::setPilot(person thePilot)
{
	inCraft[0] = thePilot;
}

person aircraft::getPilot()
{
	return inCraft[0];
}

void aircraft::setCoPilot(person theCoPilot)
{
	inCraft[1] = theCoPilot;
}

person aircraft::getCoPilot()
{
	return inCraft[1];
}

void aircraft::printDetails()
{
	cout << sign << endl << inCraft[0].getName() << endl << inCraft[1].getName() << endl;
}

aircraft::~aircraft()
{

}
