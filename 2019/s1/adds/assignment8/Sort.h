#ifndef SORT_H
#define SORT_H

#include <vector>

class Sort
{
protected:
    std::vector<int> list;
    void swap(int pos1, int pos2);

public:
    virtual void doSort() = 0;
    virtual void doSort(int bottom, int top) = 0;
    void print();
    std::vector<int> getList();

};

#endif
