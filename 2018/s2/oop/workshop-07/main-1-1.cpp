#include "animal.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	animal animal1("Elephant");
	animal1.set_name("Jim");
	cout << animal1.get_name() << endl;

	animal animal2("Cheetah");
	animal2.set_name("Stacy");
	cout << animal2.get_name() << endl;

	return 0;
}