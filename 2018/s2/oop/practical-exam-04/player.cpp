#include "person.h"
#include "player.h"
#include <string>

using namespace std;

int player::nextID = 1000;

player::player()
{
	occupation = "player";
	personID = nextID;
	nextID++;
}

player::player(std::string n, int sl, int *list, int m)
{
	name = n;
	occupation = "player";
	serviceLength = sl;
	personID = nextID;
	nextID++;
	gameTimes = list;
	numberOfGames = m;

}

int player::searchGame(int x)
{	
	int index = -1;

	for (int i = 0; i < numberOfGames; i++)
	{
		if(x == *(gameTimes + i))
		{
			index = i;
		}
	}

	return index;
}

int player::get_salary()
{
	if(serviceLength  < 20)
	{
		return salary;
	}
	else
	{
		return 3*salary;
	}
}
