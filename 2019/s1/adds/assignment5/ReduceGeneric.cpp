#include <vector>
#include "ReduceGeneric.h"

using namespace std;

vector<int> ReduceGeneric::reduce(vector<int> inputList)
{
	store.push_back( binaryOperator(inputList[0],inputList[1]) );
	for (int i = 2; i < inputList.size(); i++)
	{
		store[0] = binaryOperator(store[0],inputList[i]);
	}
	return store;
}