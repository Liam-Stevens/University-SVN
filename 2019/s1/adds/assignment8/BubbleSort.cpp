#include "BubbleSort.h"
#include "Sort.h"
#include <vector>

using namespace std;

BubbleSort::BubbleSort(int array[], int size) {

    for (int i = 0; i < size; i++)
    {
        list.push_back(array[i]);
    }

}

void BubbleSort::doSort() {
    bool sorted;

    do
    {
        sorted = true;

        for(int i = 0; i < (signed int)(list.size() - 1); i++)
        {
            if (list[i] > list[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }

    }
    while(sorted != true);

}
