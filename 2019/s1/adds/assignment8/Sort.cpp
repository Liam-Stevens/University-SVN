#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;

void Sort::print() {
    //Prints each element of the vector followed by a space
    for (int i = 0; i < (signed int)(list.size()); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void Sort::swap(int pos1, int pos2) {
    //Swaps the positions in the vector of pos1 and pos2
    int temp = list[pos2];
    list[pos2] = list[pos1];
    list[pos1] = temp;
}

vector<int> Sort::getList() {
    //Returns the vector
    return list;
}
