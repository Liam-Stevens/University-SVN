#include <iostream>
#include "meerkat.h"
#include <string>

using namespace std;

int main()
{
  meerkat meer1;
  meerkat meer2;
  meerkat meer3;
  meerkat meer4;

  meer1.setName("John");
  meer1.setAge(21);
  meer1.getName();
  meer1.getAge();

  meer2.setName("Steve");
  meer2.setAge(12);
  meer2.getName();
  meer2.getAge();

  meer3.setName("Kevin");
  meer3.setAge(91);
  meer3.getName();
  meer3.getAge();

  meer4.setName("Nevil");
  meer4.setAge(2);
  meer4.getName();
  meer4.getAge();

  return 0;
}
