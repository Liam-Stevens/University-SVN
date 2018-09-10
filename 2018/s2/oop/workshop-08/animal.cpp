#include "animal.h"
#include <string>

using namespace std;

int animal::count = 0;

animal::animal()
{
	count++;
	id = count;
	name = "?";
	species = "?";
}

animal::animal(std::string aSpecies)
{
	count++;
	id = count;
	name = "?";
	species = aSpecies;
}

void animal::set_name(std::string aName)
{
	name = aName;
}

std::string animal::get_species()
{
	return species;
}    

std::string animal::get_name()
{
	return name;
}

int animal::get_ID()
{
	return id;
}