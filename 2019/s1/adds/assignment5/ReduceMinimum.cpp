#include "ReduceGeneric.h"
#include "ReduceMinimum.h"

using namespace std;

int ReduceMinimum::binaryOperator(int x, int y)
{
	//Checks if lower number
	if (x < y)
	{
		return x;
	}
	return y;
}