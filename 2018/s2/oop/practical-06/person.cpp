#include <string>
#include "person.h"

using namespace std;

int person::count = 0;


person::person()
{
	id = count;
	count++;
	name = "?";
	psalary = 0;
}

person::person(std::string myName, int Salary)
{
	id = count;
	count++;
	name = myName;
	psalary = Salary;
}

string person::getName() 
{
  return name;
}

int person::getSalary() 
{
  return psalary;
}

void person::setName(std::string myName) 
{
  name = myName;
}

void person::setSalary(int mySalary) 
{
  psalary = mySalary;
}

person::~person()
{

}
