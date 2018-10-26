#ifndef COACH_H
#define COACH_H

#include <string>

class coach : public person
{
	static int nextID;

public:
	coach();
	coach(std::string n, int sl);

	//getters
	virtual int get_salary();

};

#endif