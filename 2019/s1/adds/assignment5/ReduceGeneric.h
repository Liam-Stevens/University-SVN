#ifndef REDUCEGENERIC_H
#define REDUCEGENERIC_H

#include <vector>

class ReduceGeneric
{
private:
	virtual int binaryOperator(int x, int y) = 0;
	std::vector<int> store;

public:
	std::vector<int> reduce(std::vector<int> inputList);

};

#endif