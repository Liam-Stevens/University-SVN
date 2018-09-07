#include "player.h"
#include <string>

player::player()
{
	pName = "?";
	number = 0;
}

player::player(int jerseyNumber, std::string playerName)
{
	pName = playerName;
	number = jerseyNumber;
}

std::string player::get_name()
{
	return pName;
}

int player::get_jersey_number()
{
	return number;
}