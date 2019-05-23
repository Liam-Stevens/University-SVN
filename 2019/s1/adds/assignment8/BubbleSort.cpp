#include "BubbleSort.h"
#include "Sort.h"
#include <vector>

using namespace std;

BubbleSort::BubbleSort(int array[], int size) {
    //inserts the array into a vector of the appropriot size
    for (int i = 0; i < size; i++) {
        list.push_back(array[i]);
    }

}

void BubbleSort::doSort() {
    bool sorted;
    //Will execute until sorted
    do
    {
        sorted = true;
        //Iterates over each element of the vector
        for(int i = 0; i < (signed int)(list.size() - 1); i++)
        {
            //Checks and swaps element which are next to eachother if not in order
            if (list[i] > list[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }

    }
    while(sorted != true);

}
