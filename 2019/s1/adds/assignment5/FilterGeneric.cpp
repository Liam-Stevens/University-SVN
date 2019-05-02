#include <vector>
#include "FilterGeneric.h"

using namespace std;

std::vector<int> FilterGeneric::filter(vector<int> inputList)
{
	for(int i = 0; i < inputList.size(); i++)
	{
		if(g(inputList[i]) == true)
		{
			listFiltered.push_back(inputList[i]);
		}
	}
	return listFiltered;
}