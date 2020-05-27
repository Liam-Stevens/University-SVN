#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include "data.h"

extern bool verifyArgs(int, std::string, std::string);

extern bool readData(std::string, struct data *, bool);

extern int getKey(std::string, struct data);

extern void copyKeys(struct data, struct data *);

extern bool translateToWeight(std::string, struct data *);


//Debug
extern void printLabels(struct data);

extern void printLinks(struct data);

#endif
