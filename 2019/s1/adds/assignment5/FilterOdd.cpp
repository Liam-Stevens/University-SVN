#include "FilterGeneric.h"
#include "FilterOdd.h"

using namespace std;

bool FilterOdd::g(int x)
{
	//Checks if there is a remainder when divided by two
	if (x%2 == 0)
	{
		return false;
	}
	return true;
}