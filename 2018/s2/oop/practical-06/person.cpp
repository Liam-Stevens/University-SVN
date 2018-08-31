#include <string>
#include "person.h"

using namespace std;

int person::count = 0;


person::person()
{
	id = count;
	count++;
	name = "?";
	salary = 0;
}

string person::getName() 
{
  return name;
}

int person::getSalary() 
{
  return salary;
}

void person::setName(std::string myName) 
{
  name = myName;
}

void person::setSalary(int mySalary) 
{
  salary = mySalary;
}

person::~person()
{

}
