#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal
{
protected:
	static int id;
	int animalID;
	int volume;
	std::string name;


public:
	animal();
	animal(std::string n, int v) ;   // creates an animal with name n and body volume v.

	std::string get_name();
	int get_animalID();
	int get_volume();

	void set_name(std::string newName);
	void set_animalID(int newID);
	void set_volume(int newVolume);

};

#endif