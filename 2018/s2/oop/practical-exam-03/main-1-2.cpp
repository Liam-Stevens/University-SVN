#include "player.h"
#include "team.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	//Creates player to be put in team
	player player1(3,"John");

	//Creates teams
	team team1();
	team team2(5, "Falcon");

	//Gets information on team2
	team2.get_current_number_of_players();
	team2.get_name();
	team2.get_roster();

	//Adds player1 to team2
	team2.add_player(player1);

	return 0;
}