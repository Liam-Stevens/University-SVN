#include "animal.h"
#include "vegie.h"
#include <string>

using namespace std;

int vegie::count = 0;

vegie::vegie(std::string aSpecies)
{
	species = aSpecies;
	favFood = "Grass";
}

void vegie::set_favourite_food(std::string aVegie)
{
	favFood = aVegie;
}

std::string vegie::getFavouriteFood()
{
	return favFood;
}