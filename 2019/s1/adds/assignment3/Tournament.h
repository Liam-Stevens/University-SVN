#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "computer.h"
#include <string>

class Tournament
{
private:
	computer* match[8];
	int roundNum;
	int activePlayers;
	int maxPlayers;
	int plays;
	int scoreP1;
	int scoreP2;

public:
	
	Tournament();
	Tournament(std::string newPlayer1, std::string newPlayer2, 
		std::string newPlayer3, std::string newPlayer4, std::string newPlayer5, 
		std::string newPlayer6, std::string newPlayer7, std::string newPlayer8);

	void compete();
	void createPlayer(int index, std::string playerType);
};

#endif