#include "player.h"
#include <string>

player::player()
{
	name = "?";
	number = 0;
}

player::player(int jerseyNumber, std::string playerName)
{
	name = playerName;
	number = jerseyNumber;
}

std::string player::get_name()
{
	return name;
}

int player::get_jersey_number()
{
	return number;
}