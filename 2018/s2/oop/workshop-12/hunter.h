#ifndef HUNTER_H
#define HUNTER_H

#include "animal.h"
#include <string>

class hunter : public animal
{
	static int nextID;
	int kills;               // how many kills have been recorded, initialised to 0

public:
	hunter(std::string n, int v);  // create a hunter with name n and body volume v

	std::string get_name();
	int get_kills();
	void set_kills(int newKills);
};

#endif