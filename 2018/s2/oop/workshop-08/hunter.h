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
	hunter(std::string aSpecies);
	void record_kill(std::string kill);
	int numberOfKills();
	
	std::vector<std::string> get_kills();
};

#endif