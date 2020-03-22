#ifndef MAP_H
#define MAP_H

#include <vector>

struct map {
    int sizeX;
    int sizeY;
    int startX;
    int startY;
    int endX;
	int endY;

	std::vector< std::vector<int> > view;
};

#endif
