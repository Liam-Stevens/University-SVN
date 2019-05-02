#include "FilterGeneric.h"
#include "FilterNonPositive.h"

using namespace std;

bool FilterNonPositive::g(int x)
{
	if(x < 0)
	{
		return true;
	}
	return false;
}