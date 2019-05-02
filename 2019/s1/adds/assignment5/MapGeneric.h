#ifndef MAPGENERIC_H
#define MAPGENERIC_H

#include <vector>

class MapGeneric
{
private:
	virtual int f(int x) = 0;
/*
protected:
	std::vector<int> list;
*/

public:
	std::vector<int> map(std::vector<int> inputList);

};

#endif