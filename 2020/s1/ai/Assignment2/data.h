#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

struct data {
    std::vector<std::string> ratings;
	std::vector< std::vector<float> > attributes;
};

struct splits {
    int bestAttribute;
    float bestSplitValue;
};

#endif
