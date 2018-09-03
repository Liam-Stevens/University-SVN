#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal
{
	static int count;
	int id;

protected:
	std::string name;
	std::string species;


public:
	animal();
	animal(std::string aSpecies);
	void set_name(std::string aName);
	
	std::string get_species();      
	std::string get_name();
	int get_ID();
};

#endif