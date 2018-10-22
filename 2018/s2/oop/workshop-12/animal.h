#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal
{
	static int id;
	int animalID
	int volume;
	std::string name;


public:
	animal(std::string n, int v) ;   // creates an animal with name n and body volume v.

	std::string get_name();
	int get_animalID();
	int get_volume();

	std::string set_name(std::string newName);
	int set_animalID(int newID);
	int set_volume(int newVolume);

};

#endif