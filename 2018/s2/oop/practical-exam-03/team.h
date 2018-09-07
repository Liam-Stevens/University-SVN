#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

class team
{
	//Private variables
	int numOfPlayers;
	int size;
	std::string teamName;
	std::vector<player> teamList;

public:
	//Constructors
	team();
	team(int max_size, std::string name);

	//Getters
	int get_current_number_of_players();
	std::string get_name();
	player * get_roster();

	//Adders
	bool add_player(player new_player);

	//Destructor
	~team();
};

#endif