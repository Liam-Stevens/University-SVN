#include "animal.h"
#include "hunter.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	hunter hunter1("Cheetah");
	hunter1.set_name("Stacy");
	cout << hunter1.get_name() << endl;

	hunter1.record_kill("Mouse");
	hunter1.record_kill("Gazelle");
	hunter1.record_kill("Gazelle");
	hunter1.record_kill("Hyena");
	hunter1.record_kill("Rabbit");
	hunter1.record_kill("Rabbit");

	vector<string> kill1 = hunter1.get_kills();

	for (int i = 0; i < hunter1.numberOfKills(); i++)
	{
		cout << kill1[i] << endl;
	}


	return 0;
}