#include "person.h"
#include "coach.h"
#include <string>

using namespace std;

int coach::nextID = 0;

coach::coach()
{
	personID = nextID;
	nextID++;
}

coach::coach(std::string n, int sl)
{
	name = n;
	serviceLength = sl;
	personID = nextID;
	nextID++;
}

int coach::get_salary()
{
	if(serviceLength < 10)
	{
		return salary;
	}
	else
	{
		return 2*salary;
	}
}
