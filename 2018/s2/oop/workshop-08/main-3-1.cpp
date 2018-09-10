#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	hunter hunter1("Lion");
	hunter hunter2("Lion");
	hunter hunter3("Lion");
	vegie vegie1("Cow");
	vegie vegie2("Cow");

	animal** container = new animal*[5];

	container[0] = &hunter1;
	container[1] = &hunter2;
	container[2] = &hunter3;
	container[3] = &vegie1;
	container[4] = &vegie2;

	delete[] container;

	return 0;
}