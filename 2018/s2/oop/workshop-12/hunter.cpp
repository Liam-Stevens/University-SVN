#include "hunter.h"
#include "animal.h"
#include <string>

using namespace std;

int hunter::nextID = 1000;

hunter::hunter(string n, int v)
{
	animalID = nextID;
	nextID++;
	name = n;
	volume = v;
	kills = 0;
}

get_name()
{
	string temp = "Hunter: " + name;
	return temp;
}

int hunter::get_kills()
{
	return kills;
}

int hunter::set_kills(int newKills)
{
	kills = newKills;
}

};