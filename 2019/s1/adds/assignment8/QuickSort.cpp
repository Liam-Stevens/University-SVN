#include "QuickSort.h"
#include "Sort.h"
#include <vector>

using namespace std;

QuickSort::QuickSort(int array[], int size) {

    for (int i = 0; i < size; i++)
    {
        list.push_back(array[i]);
    }

}

void QuickSort::doSort() {
    doSort(0, list.size()-1);
}

void QuickSort::doSort(int bottom, int top) {

    if (bottom < top)
    {
        int pivotIndex = partition(bottom,top);
        doSort(bottom, pivotIndex-1);
        doSort(pivotIndex+1, top);
    }

}

int QuickSort::partition(int bottom, int top) {

    int pivot;
    if (top-bottom > 2) {
        pivot = list[bottom+2];
        swap(bottom+2,top);
    } else {
        pivot = list[top];
    }

    int pivotIndex = bottom-1;
    for (int tracer = bottom; tracer < top; tracer++) {

        if (list[tracer] <= pivot) {
            pivotIndex++;
            swap(pivotIndex, tracer);
        }
    }
    
    swap(pivotIndex+1, top);
    return(pivotIndex+1);
}
