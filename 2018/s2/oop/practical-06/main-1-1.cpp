#include <string>
#include "meerkat.h"

using namespace std;

int main
{
	Meerkat meer1;
	Meerkat meer2;
	Meerkat meer3;
	Meerkat meer4;

	meer1.getName();
	meer1.getAge();
	meer1.setName("John");
	meer1.setAge(21);
	meer1.getName();
	meer1.getAge();

	meer2.getName();
	meer2.getAge();
	meer2.setName("Steve");
	meer2.setAge(12);
	meer2.getName();
	meer2.getAge();

	meer3.getName();
	meer3.getAge();
	meer3.setName("Kevin");
	meer3.setAge(91);
	meer3.getName();
	meer3.getAge();

	meer4.getName();
	meer4.getAge();
	meer4.setName("Nevil");
	meer4.setAge(2);
	meer4.getName();
	meer4.getAge();

	return 0;
}