#include "animal.h"
#include <string>

using namespace std;


animal::animal()
{
	animalID = 0;
	name = "?";
	volume = 0;
}

animal::animal(std::string n, int v)
{
	animalID = 0;
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

void animal::set_name(std::string newName)
{
	name = newName;
}

void animal::set_animalID(int newID)
{
	animalID = newID;
}

void animal::set_volume(int newVolume)
{
	volume = newVolume;
}

