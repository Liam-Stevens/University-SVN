#include "animal.h"
#include <string>

using namespace std;

int animal::id = 0;

animal::animal()
{
	animalID = id;
	id++;
	name = "?";
	volume = 0;
}

animal::animal(std::string n, int v)
{
	animalID = id;
	id++;
	name = n;
	volume = v;
}

std::string animal::get_name()
{
	return name;
}

int animal::get_animalID()
{
	return animalID;
}

int animal::get_volume()
{
	return volume;
}

std::string animal::set_name(std::string newName)
{
	name = newName;
}

int animal::set_animalID(int newID)
{
	animalID = newID;
}

int animal::set_volume(int newVolume)
{
	volume = newVolume;
}

