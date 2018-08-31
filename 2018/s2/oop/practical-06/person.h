#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
  static int count;
  int id;
  std::string name;
  int psalary;

 public:
  person();
  person(std::string myName, int Salary);

  // getters
  std::string getName();
  int getSalary();

  // setters
  void setName(std::string myName);
  void setSalary(int mySalary);		

  ~person();
};

#endif