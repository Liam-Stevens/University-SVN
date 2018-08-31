// 'guards' to prevent redeclaration of Panda class
#ifndef PANDA_H
#define PANDA_H

#include <string>

// no namespaces in include file!!!

// Class definition for a Panda
class Meerkat
{
  static int count;
  int id;
  std::string name;
  int age;

 public:
  Meerkat();

  // getters
  std::string getName();
  int getAge();

  // setters
  void setName(std::string meerName);
  void setAge(int meerAge);		

  ~Meerkat();
};

#endif