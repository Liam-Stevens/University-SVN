#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include <string>

class zoo
{
	std::string name ;                          // the zoo's name
	int number_of_animals ;                // the number of animals in the zoo
	animal **animals ;    

public:
	zoo(std::string n,int cows,int lions);      // create a zoo with the given number of cows and lions
	std::string get_name();
	int get_number_of_animals();
	animal get_animals();
};

#endif