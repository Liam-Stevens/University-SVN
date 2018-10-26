#include "person.h"
#include <string>

using namespace std;

person::person()
{
	name = "?";
	occupation = "?";
	serviceLength = 0;
	salary = 0;
}

person::person(std::string n, std::string o, int sl)
{
	name = n;
	occupation = o;
	serviceLength = sl;
	salary = 0;
}

//getters
std::string person::get_name()
{
	return name;
}

std::string person::get_occupation()
{
	return occupation;
}

int person::get_personID()
{
	return personID;
}

//setters
void person::set_name(std::string newName)
{
	name = newName;
}

void person::set_occupation(std::string newOccupation)
{
	occupation = newOccupation;
}

void person::set_salary(int newSalary)
{
	salary = newSalary;
}

