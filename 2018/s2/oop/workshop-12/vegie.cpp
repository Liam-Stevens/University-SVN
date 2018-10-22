#include "vegie.h"
#include "animal.h"
#include <string>

using namespace std;

int vegie::nextID = 100;

vegie::vegie(string n,int v)
{
	animalID = nextID;
	nextID++;
	name = n;
	volume = v;
	favourite_food = "?";
}   

std::string vegie::get_name()
{
	return "Safe: " + name;
}

std::string vegie::get_favourite_food()
{
	return favourite_food;
}

void vegie::set_favourite_food(std::string newFood)
{
	favourite_food = newFood;
}
