#include "animal.h"
#include "vegie.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	vegie vegie1("Goat");
	animal animal1("Goat");
	vegie vegie2("Goat");
	vegie1.set_favourite_food("Hats");
	cout << vegie1.getFavouriteFood() << endl;
	cout << vegie2.get_species() << endl;
	cout << vegie2.get_ID() << endl;

	return 0;
}