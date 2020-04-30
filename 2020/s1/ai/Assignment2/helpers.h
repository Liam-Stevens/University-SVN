#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include "data.h"

extern bool verify(int, std::string, std::string, int);

extern bool readData(std::string, struct data *);

extern void sortAttribute(struct data *, int);

extern float calcGain(struct data, int, float);

#endif
