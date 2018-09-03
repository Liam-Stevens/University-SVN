#include "animal.h"
#include "hunter.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int hunter::count = 0;

hunter::hunter(std::string aSpecies)
{
	count++;
	id = count;
	name = "?";
	species = aSpecies;
	kills = 0;
}

void hunter::record_kill(std::string kill)
{
	kill_list.push_back(kill);
	kills++;
}

int hunter::numberOfKills()
{
	return kills;
}

vector<string> hunter::get_kills()
{
	return kill_list;
}