#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

struct data {
    std::vector<std::string> keys;
    std::vector< std::vector<int> > weights;
};

#endif
