#include "vegie.h"
#include "hunter.h"
#include "animal.h"
#include "zoo.h"
#include <string>

using namespace std;

zoo::zoo(std::string n,int cows,int lions)
{
	name = n;
	if (cows > 0 || lions > 0)
	{
		number_of_animals = cows + lions;
		animals = new animal*[number_of_animals];

		for(int i = 0; i < cows; i++)
		{
			vegie myCow("Daisy",100);
			**(animals + i) = myCow;
		}
		for(int i = cows; i < number_of_animals; i++)
		{
			hunter myLion("Clarence",50);
			**(animals + i) = myLion;
		}
	}
	else
	{
		number_of_animals = 0;
	}
}

std::string zoo::get_name()
{
	return name;
}

int zoo::get_number_of_animals()
{
	return number_of_animals;
}

animal ** zoo::get_animals()
{
	return animals;
}

zoo::~zoo()
{
	delete[] animals;
}
