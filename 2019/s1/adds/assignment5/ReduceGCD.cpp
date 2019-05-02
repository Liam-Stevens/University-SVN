#include "ReduceGeneric.h"
#include "ReduceGCD.h"

using namespace std;

int ReduceGCD::binaryOperator(int x, int y)
{
	//Checks divisibility until it finds the gcd
	if (y == 0)
	{
		return x;
	}
	return binaryOperator(y, x%y);
}