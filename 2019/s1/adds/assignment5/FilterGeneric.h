#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H

#include <vector>

class FilterGeneric
{
private:
	virtual bool g(int x) = 0;
	std::vector<int> listFiltered;

public:
	std::vector<int> filter(std::vector<int> inputList);

};

#endif