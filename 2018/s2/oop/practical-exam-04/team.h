#ifndef TEAM_H
#define TEAM_H

#include "person.h"
#include <string>

class team
{	
	person **teamPlayers;

public:
	team();

	person **getTeam();

	~team();

};

#endif