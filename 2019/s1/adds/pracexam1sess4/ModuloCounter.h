/*  
    Base class for a counter
*/

#ifndef MODULO_COUNTER_H
#define MODULO_COUNTER_H

#include <string>
#include "Counter.h"

class ModuloCounter: public Counter{
 public:
  // Constructor - takes starting value and limit. If limit is reached counter goes back 
  // to zero. 
  ModuloCounter();
  ModuloCounter(int val2,int limit2);
  virtual void inc();

 protected:
  // field variable
  int limit;
};
#endif // MODULO_COUNTER_H
