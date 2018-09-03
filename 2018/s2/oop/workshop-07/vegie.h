#ifndef VEGIE_H
#define VEGIE_H

#include <string>

class vegie : public animal
{
	static int count;
	int id;
	std::string favFood;

public:

	vegie(std::string aSpecies);  // create a vegie of the given species, its favourite food is "Grass"
	void set_favourite_food(std::string aVegie); // change the vegie's favourite food
	std::string getFavouriteFood();
};

#endif