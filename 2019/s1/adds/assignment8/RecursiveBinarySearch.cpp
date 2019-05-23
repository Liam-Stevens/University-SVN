#include "RecursiveBinarySearch.h"
#include <vector>

using namespace std;

RecursiveBinarySearch::RecursiveBinarySearch(int find, vector<int> arr) {
    //Sets search term and search vector
    searchTerm = find;
    list = arr;
}

bool RecursiveBinarySearch::search() {
    //Kick starts the recursive search
    return search(0, (signed int)(list.size()-1));
}

bool RecursiveBinarySearch::search(int bottom, int top) {

    //Finds the middle of the search area
    int midPoint = (bottom+top)/2;

    //Checks if the middle is the search term or it failed
    if(list[midPoint] == searchTerm) {
        return true;
    } else if (bottom == top) {
        return false;
    }

    //Recurs the search if either the term is too high or too low
    if(list[midPoint] > searchTerm) {
        return search(bottom, midPoint-1);
    } else if (list[midPoint] < searchTerm) {
        return search(midPoint+1, top);
    } else {
        return false;
    }
}
