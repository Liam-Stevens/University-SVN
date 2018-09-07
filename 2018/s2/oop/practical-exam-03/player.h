#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
	//Private variables
	int number;
	std::string pName;

public:
	//Constructors
	player();
	player(int jerseyNumber, std::string playerName);

	//Getters
	std::string get_name();
	int get_jersey_number();

};

#endif