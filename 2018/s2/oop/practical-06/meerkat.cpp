#include <string>
#include "meerkat.h"

using namespace std;

// class integer - static shared by all Pandas
int Meerkat::count = 0;

// implementation of the default Panda constructor
Meerkat::Meerkat()
{
	id = count;
	count++;
	name = "?";
	age = 0;
}

string Meerkat::getName() 
{
  return name;
}

int Meerkat::getAge() 
{
  return age;
}

void Meerkat::setName(std::string meerName) 
{
  name = meerName;
}

void Meerkat::setAge(int meerAge) 
{
  name = meerAge;
}


// implementation of the default Panda destructor
Meerkat::~Meerkat()
{
  // delete any memory allocated by new
}
