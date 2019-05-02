#include <vector>
#include "MapGeneric.h"

using namespace std;

vector<int> MapGeneric::map(vector<int> inputList)
{
	for(int i = 0; i < inputList.size(); i++)
	{
		inputList[i] = f(inputList[i]);
	}
	return inputList;
}