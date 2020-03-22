#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include "map.h"

extern bool verify(int, std::string, std::string, std::string);

extern bool readMap(std::string, struct map *);

extern void convertMap(std::vector<std::string>);



#endif
