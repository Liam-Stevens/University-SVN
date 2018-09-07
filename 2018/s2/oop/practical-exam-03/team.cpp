#include "player.h"
#include "team.h"
#include <string>
#include <vector>

using namespace std;

team::team()
{
	size = 0;
	numOfPlayers = 0;
	teamName = "?";
}

team::team(int max_size, std::string name)
{
	size = max_size;
	numOfPlayers = 0;
	teamName = name;
}

int team::get_current_number_of_players()
{
	return numOfPlayers;
}

std::string team::get_name()
{
	return teamName;
}

player * team::get_roster()
{
	player * ptr = &teamList[0];
	return ptr;
}

bool team::add_player(player new_player)
{
	//Checks if the team is full
	if(numOfPlayers >= size)
	{
		return false;
	}
	teamList.push_back(new_player);
	numOfPlayers++;
	return true;
}

team::~team()
{
	
}