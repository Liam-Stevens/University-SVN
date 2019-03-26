#include "Tournament.h"
#include "referee.h"
#include "computer.h"
#include "RandomComputer.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include "Crescendo.h"
#include "PaperDoll.h"
#include "FistfullODollars.h"

#include <string>
#include <iostream>

using namespace std;

Tournament::Tournament()
{
	createPlayer(0, "Crescendo");
	createPlayer(1, "Avalanche");
	createPlayer(2, "Toolbox");
	createPlayer(3, "Toolbox");
	createPlayer(4, "PaperDoll");
	createPlayer(5, "PaperDoll");
	createPlayer(6, "Bureaucrat");
	createPlayer(7, "FistfullODollars");
	roundNum = 1;
	maxPlayers = 8;
	plays = 5;
}

Tournament::Tournament(std::string newPlayer1, std::string newPlayer2, 
		std::string newPlayer3, std::string newPlayer4, std::string newPlayer5, 
		std::string newPlayer6, std::string newPlayer7, std::string newPlayer8)
{
	createPlayer(0, newPlayer1);
	createPlayer(1, newPlayer2);
	createPlayer(2, newPlayer3);
	createPlayer(3, newPlayer4);
	createPlayer(4, newPlayer5);
	createPlayer(5, newPlayer6);
	createPlayer(6, newPlayer7);
	createPlayer(7, newPlayer8);
	roundNum = 1;
	maxPlayers = 8;
	plays = 5;
}

void Tournament::compete()
{
	//Sets required variables for active tests
	activePlayers = maxPlayers;
	referee judge;
	string *ptr1;
	string *ptr2;
	string tempResults;
	scoreP1 = 0;
	scoreP2 = 0;

	//Start of the tournament
	for (roundNum; roundNum < maxPlayers/2; roundNum++)
	{
		for (int i = 0; i < (activePlayers/2); i++)
		{
			//Gets the play info from the computers
			//cout << "R: " << roundNum << " | M: "<< i + 1 << endl;
			ptr1 = match[2*i]->getStrat();
			ptr2 = match[2*i+1]->getStrat();
			judge.setCompetitors(ptr1,ptr2);
			judge.compare();
			tempResults = judge.getResults();
			//cout << tempResults << endl;
			//Check the score
			for (int j = 0; j < 5; j++)
			{
				if (tempResults[j] == 'T')
				{}
				else if (tempResults[j] == 'W')
				{
					scoreP1++;
				}
				else if (tempResults[j] == 'L')
				{
					scoreP2++;
				}
			}
			//cout << match[2*i]->getType() << " # " << match[2*i+1]->getType() << endl;
			//cout << scoreP1 << "-" << scoreP2 << endl;
			//Assign next round based on win
			if (scoreP1 == scoreP2)
			{
				match[i] = match[2*i];
			} 
			else if (scoreP1 > scoreP2)
			{
				match[i] = match[2*i];
			}
			else if (scoreP1 < scoreP2)
			{
				match[i] = match[2*i+1];
			}
			scoreP1 = 0;
			scoreP2 = 0;
		}
		activePlayers = activePlayers/2;
	}
	//Announces the winner
	cout << match[0]->getType() << endl;
}

void Tournament::compare()
{

}

void Tournament::printResults()
{

}

void Tournament::createPlayer(int index, std::string playerType)
{
	if (playerType == "RandomComputer")
	{
		match[index] = new RandomComputer;
	}
	else if (playerType == "Avalanche")
	{
		match[index] = new Avalanche;
	}
	else if (playerType == "Bureaucrat")
	{
		match[index] = new Bureaucrat;
	}
	else if (playerType == "Toolbox")
	{
		match[index] = new Toolbox;
	}
	else if (playerType == "Crescendo")
	{
		match[index] = new Crescendo;
	}
	else if (playerType == "PaperDoll")
	{
		match[index] = new PaperDoll;
	}
	else if (playerType == "FistfullODollars")
	{
		match[index] = new FistfullODollars;
	}
}