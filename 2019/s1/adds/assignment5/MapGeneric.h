#ifndef MAPGENERIC_H
#define MAPGENERIC_H

#include <vector>

class MapGeneric
{
private:
	virtual int f(int x) = 0;
	std::vector<int> mapper;

public:
	std::vector<int> map(std::vector<int> inputList);

};

#endif