#ifndef STALL_H
#define STALL_H

#include <string>

class stall
{
  static int count;
  std::string name;
  double money;
  //Arrays of item, their price and quantity avaliable

 public:
	stall();
	stall(std::string name, );

	~stall();
};

#endif