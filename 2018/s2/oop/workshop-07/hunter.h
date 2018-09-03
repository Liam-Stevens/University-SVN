#ifndef HUNTER_H
#define HUNTER_H

#include <vector>
#include <string>

class hunter : public animal
{
	static int count;
	int id;
	int kills;
	std::vector<std::string> kill_list;

public:
	hunter(std::string aSpecies);         // create a hunter of the given species
	void record_kill(std::string kill);   // add a new kill to the end of the hunter's list of kills
	int numberOfKills();             // how many kills have been recorded

	// implement ONE of the following
	std::vector<std::string> get_kills();      // return a vector of all kills by this hunter
};

#endif