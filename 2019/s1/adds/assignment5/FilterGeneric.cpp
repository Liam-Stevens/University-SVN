#include <vector>
#include "FilterGeneric.h"

using namespace std;

std::vector<int> FilterGeneric::filter(vector<int> inputList)
{
	
	//Stores filtered integer, removes integer from map list then recurs
	if (inputList.size() == 0)
	{
		return inputList;
	}
	if (g(inputList[0]) == true)
	{
		listFiltered.push_back(inputList[0]);
	}
	inputList.erase(inputList.begin());
	filter(inputList);

	return listFiltered;
}