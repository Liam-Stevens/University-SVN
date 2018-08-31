#include <string>
#include "meerkat.h"

using namespace std;

int Meerkat::count = 0;

Meerkat::Meerkat()
{
	id = count;
	count++;
	name = "?";
	age = 0;
}

void Meerkat::setName(std::string meerName)
{
	name = meerName;
}

string Meerkat::getName()
{
	return name;
}

void Meerkat::setAge(int meerAge)
{
	age = meerAge;
}

int Meerkat::getAge()
{
	return age;
}

Meerkat::~Meerkat()
{

}