#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include "data.h"

//Verifies the input arguments
extern bool verifyArgs(int);

//Read the file to a vector
extern bool readData(std::string, struct data *, bool);

//Get the key value from name
extern int getKey(std::string, struct data);

//Copy Keys from one struct to another
extern void copyKeys(struct data, struct data *);

//Translate from string to weight vector
extern bool translateToWeight(std::string, struct data *);

//Sort Keys using Bubble Sort
extern void sortKeys(struct data *);


//Debug

//Prints labels
extern void printLabels(struct data);

//Prints a table of links
extern void printLinks(struct data);

#endif
