#include "player.h"
#include "team.h"
#include <string>
#include <vector>

using namespace std;

team::team()
{
	size = 4;
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
	return &teamList[0];
}

bool team::add_player(player new_player)
{
	if(numOfPlayers < size)
	{
		teamList.push_back(new_player);
		numOfPlayers++;
		return true;
	}
	return false;
}

team::~team()
{
	//delete[] &teamList;
}