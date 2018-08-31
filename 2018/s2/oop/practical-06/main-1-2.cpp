#include <iostream>
#include "person.h"
#include <string>

using namespace std;

int main()
{
  person meer1;
  person meer2;
  person meer3;
  person meer4;

  meer1.getName();
  meer1.getSalary();
  meer1.setName("John");
  meer1.setSalary(21);
  meer1.getName();
  meer1.getSalary();

  meer2.getName();
  meer2.getSalary();
  meer2.setName("Steve");
  meer2.setSalary(12);
  meer2.getName();
  meer2.getSalary();

  meer3.getName();
  meer3.getSalary();
  meer3.setName("Kevin");
  meer3.setSalary(91);
  meer3.getName();
  meer3.getSalary();

  meer4.getName();
  meer4.getSalary();
  meer4.setName("Nevil");
  meer4.setSalary(2);
  meer4.getName();
  meer4.getSalary();

  return 0;
}
