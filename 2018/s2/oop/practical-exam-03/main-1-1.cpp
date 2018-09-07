#include "player.h"
#include <string>

int main()
{
	player player1();
	player player2(21,"John");
	player2.get_name();
	player2.get_jersey_number();

	return 0;
}