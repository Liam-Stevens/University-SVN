#include "Counter.h"

using namespace std;

// put implementation code for the constructor and functions here
Counter::Counter()
{
	
}

Counter::Counter(int val2)
{
	val = val2;
}

int Counter::get_val()
{
	return val;
}

void Counter::reset()
{
	val = 0;
}

void Counter::inc()
{
	val++;
}

