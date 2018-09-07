#include "player.h"
#include "team.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	player player1(3,"John");

	team team1();
	team team2(5, "Falcon");

	team2.get_current_number_of_players();
	team2.get_name();
	team2.get_roster();

	team2.add_player(player1);

	return 0;
}