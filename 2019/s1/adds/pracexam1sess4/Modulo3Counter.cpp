#include "Modulo3Counter.h"

// put implementation code for the constructor and functions here

Modulo3Counter::Modulo3Counter(int val2)
{
	limit = 3;
	if (val2 >= limit)
	{
		val = val2%limit;
	}
	else
	{
		val = val2;
	}
}