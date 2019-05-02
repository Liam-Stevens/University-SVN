#include <vector>
#include "MapGeneric.h"

using namespace std;

vector<int> MapGeneric::map(vector<int> inputList)
{
	//Maps integer, removes integer from map list, then recurs
	if (inputList.size() == 0)
	{
		return inputList;
	}
	mapper.push_back(f(inputList[0]));
	inputList.erase(inputList.begin());
	map(inputList);

	return mapper;
}