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

/*
	animal * ptr1 = &hunter1;
	animal * ptr2 = &hunter2;
	animal * ptr3 = &hunter3;
	animal * ptr4 = &vegie1;
	animal * ptr5 = &vegie2;
	*/

	//int collection[5] = {ptrh1,ptrh2,ptrh3,ptrv1,ptrv2};
	animal** container = new animal*[5];

	container[0] = &hunter1;
	container[1] = &hunter2;
	container[2] = &hunter3;
	container[3] = &vegie1;
	container[4] = &vegie2;

/*
	for(int i = 0; i < 5; i++)
	{
		container[i] = ptr(i);
	}
	*/

	return 0;
}