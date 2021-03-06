#include <iostream>
#include <string>

#include "computer.h"
#include "referee.h"
#include "Tournament.h"
#include "RandomComputer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"

using namespace std;

int main()
{
	string line;
	string plr[8];
	int playerCap = 0;

	//Takes inputs until all player slots are filled
	do {
		cin >> line;
		plr[playerCap] = line;
		playerCap++;
	}
	while(playerCap < 8);

	//Initiates the Tournament
	Tournament Tournament1(plr[0],plr[1],plr[2],plr[3],plr[4],plr[5],plr[6],plr[7]);
	Tournament1.compete();

	return 0;
}