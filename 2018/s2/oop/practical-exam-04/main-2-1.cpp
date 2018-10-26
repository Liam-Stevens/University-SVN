#include "person.h"
#include "coach.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	coach james("James", 1);
	coach james2("James", 1);
	coach james3("James", 1);
	james.set_salary(20);
	cout << james.get_salary() << endl;
	cout << james3.get_personID() << endl;

	return 0;
}