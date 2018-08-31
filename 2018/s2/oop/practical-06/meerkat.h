#ifndef MEERKAT_H
#define MEERKAT_H

#include <string>

class meerkat
{
  static int count;
  int id;
  std::string name;
  int age;

 public:
  meerkat();

  meerkat(std::string meerName, int meerAge);

  // getters
  std::string getName();
  int getAge();

  // setters
  void setName(std::string meerName);
  void setAge(int meerAge);		

  ~meerkat();
};

#endif