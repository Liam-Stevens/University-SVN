#include "ModuloCounter.h"
#include "Counter.h"

#include <iostream>


// put implementation code for the constructor and functions here
ModuloCounter::ModuloCounter()
{

}

ModuloCounter::ModuloCounter(int val2,int limit2)
{
	if (val2 >= limit2)
	{
		val = val2%limit2;
	}
	else
	{
		val = val2;
	}
	limit = limit2;
}

void ModuloCounter::inc()
{
	val++;
	if (val >= limit)
	{
		val = 0;
	}
}
