#include <iostream>
#include "person.h"
#include "aircraft.h"
#include <string>

using namespace std;

int main()
{
  person person1;
  person person2;
  person person3;

  aircraft aircraft1("delta",person1,person2);
  aircraft1.setPilot(person3);
  aircraft1.setCoPilot(person1);

  return 0;
}
