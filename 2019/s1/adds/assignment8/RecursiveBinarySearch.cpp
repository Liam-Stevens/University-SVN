#include "RecursiveBinarySearch.h"
#include <vector>

using namespace std;

RecursiveBinarySearch::RecursiveBinarySearch(int find, vector<int> arr) {
    searchTerm = find;
    list = arr;
}

bool RecursiveBinarySearch::search() {
    return search(0, (signed int)(list.size()-1));
}

bool RecursiveBinarySearch::search(int bottom, int top) {

    int midPoint = (bottom+top)/2;

    if(list[midPoint] == searchTerm) {
        return true;
    } else if (bottom == top) {
        return false;
    }

    if(list[midPoint] > searchTerm) {
        return search(bottom, midPoint-1);
    } else if (list[midPoint] < searchTerm) {
        return search(midPoint+1, top);
    } else {
        return false;
    }
}
