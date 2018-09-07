#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player
{
	int number;
	std::string name;

public:
	player();
	player(int jerseyNumber, std::string playerName);
	std::string get_name();
	int get_jersey_number();

};

#endif