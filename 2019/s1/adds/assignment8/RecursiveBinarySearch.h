#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch
{
private:
    std::vector<int> list;
    int searchTerm;

public:
    RecursiveBinarySearch(int find, std::vector<int> arr);

    bool search();
    bool search(int bottom, int top);

};

#endif
