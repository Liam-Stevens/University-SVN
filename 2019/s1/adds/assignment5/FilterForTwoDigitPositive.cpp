#include "FilterGeneric.h"
#include "FilterForTwoDigitPositive.h"

using namespace std;

bool FilterForTwoDigitPositive::g(int x)
{
	if( x < 100 && x > 9 )
	{
		return true;
	}
	return false;
}