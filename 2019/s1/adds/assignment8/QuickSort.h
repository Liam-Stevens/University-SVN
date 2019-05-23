#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : public Sort
{
public:
    QuickSort(int array[], int size);

    void doSort();
    void doSort(int bottom, int top);
    int partition(int bottom, int top);

};

#endif
