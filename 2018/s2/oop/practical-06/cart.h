#ifndef CART_H
#define CART_H

#include "meerkat.h"
#include <string>

class cart
{
  static int count2;
  int id2;
  meerkat inCart[4];
  int seat;

 public:
	cart();
	bool addMeerkat(meerkat cat);
	void emptyCart();
	void printMeerkats();

  ~cart();
};

#endif