#include "QuickSort.h"
#include "Sort.h"
#include <vector>

using namespace std;

QuickSort::QuickSort(int array[], int size) {
    //Inserts the array into a vector of the appropriot size
    for (int i = 0; i < size; i++)
    {
        list.push_back(array[i]);
    }

}

void QuickSort::doSort() {
    //Kick starts the recursive sort using whole vector
    doSort(0, list.size()-1);
}

void QuickSort::doSort(int bottom, int top) {
    //Checks if it can be partitioned
    if (bottom < top)
    {
        //Partitions vector and recurs for each side of the partition
        int pivotIndex = partition(bottom,top);
        doSort(bottom, pivotIndex-1);
        doSort(pivotIndex+1, top);
    }

}

int QuickSort::partition(int bottom, int top) {

    //Sets the pivot to be the third element if there are three elements in the partition
    int pivot;
    if (top-bottom > 2) {
        pivot = list[bottom+2];
        swap(bottom+2,top);
    } else {
        pivot = list[top];
    }

    //Iterates over all elements of the partition
    int pivotIndex = bottom-1;
    for (int tracer = bottom; tracer < top; tracer++) {
        //Moves element if less than or equal to the pivot
        if (list[tracer] <= pivot) {
            pivotIndex++;
            swap(pivotIndex, tracer);
        }
    }

    swap(pivotIndex+1, top);
    return(pivotIndex+1);
}
