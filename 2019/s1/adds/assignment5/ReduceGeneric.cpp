#include <vector>
#include "ReduceGeneric.h"

using namespace std;

vector<int> ReduceGeneric::reduce(vector<int> inputList)
{
	//Checks gcd against stored number, removes integer from map list then recurs
	if (inputList.size() == 0)
	{
		return inputList;
	}
	//Initial start for store num, then normal function
	if (store.size() == 0)
	{
		store.push_back( binaryOperator(inputList[0],inputList[1]) );
		inputList.erase(inputList.begin());
		inputList.erase(inputList.begin());
	}
	else
	{
		store[0] = binaryOperator(store[0],inputList[0]);
		inputList.erase(inputList.begin());
	}
	reduce(inputList);
	
	return store;
}