#include <string>
#include "meerkat.h"

using namespace std;

int meerkat::count = 0;


meerkat::meerkat()
{
	id = count;
	count++;
	name = "Bob";
	age = 42;
}

string meerkat::getName() 
{
  return name;
}

int meerkat::getAge() 
{
  return age;
}

void meerkat::setName(std::string meerName) 
{
  name = meerName;
}

void meerkat::setAge(int meerAge) 
{
  name = meerAge;
}

meerkat::~meerkat()
{

}
