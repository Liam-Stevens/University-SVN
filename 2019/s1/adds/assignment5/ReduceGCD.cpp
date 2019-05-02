#include "ReduceGeneric.h"
#include "ReduceGCD.h"

using namespace std;

int ReduceGCD::binaryOperator(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	return binaryOperator(y, x%y);
}