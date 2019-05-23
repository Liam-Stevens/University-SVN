#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;

void Sort::print() {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void Sort::swap(int pos1, int pos2) {
    int temp = list[pos2];
    list[pos2] = list[pos1];
    list[pos1] = temp;
}

vector<int> Sort::getList() {
    return list;
}
