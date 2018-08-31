#include <iostream>
#include "cart.h"
#include "meerkat.h"
#include <string>

using namespace std;

int main()
{
  cart cart1;
  meerkat meer1;
  meerkat meer2;
  meerkat meer3;
  meerkat meer4;
  meerkat meer5;

  cart1.addMeerkat(meer1);
  cart1.addMeerkat(meer2);
  cart1.addMeerkat(meer3);
  cart1.addMeerkat(meer4);
  cart1.addMeerkat(meer5);

  return 0;
}
