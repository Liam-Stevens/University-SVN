#include "player.h"
#include <string>

int main()
{
	//Player creation
	player player1();
	player player2(21,"John");

	//Gets player2 information
	player2.get_name();
	player2.get_jersey_number();

	return 0;
}