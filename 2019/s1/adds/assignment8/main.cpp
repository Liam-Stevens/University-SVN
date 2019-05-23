#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    //Takes inputs
    int line;
	int input[100];
	int inc = 0;
	do {
		cin >> line;
		input[inc] = line;
		inc++;
	}
    //Will continue to take inputs until it reaches an end of line, end of file or maximum array size
	while(cin.peek() != '\n' && inc < 100 && feof(stdin) == false);

    //Sorts using quicksort
    QuickSort quick(input, inc);
    quick.doSort();

    //Passes the sorted list to the search
    vector<int> listPass = quick.getList();
    RecursiveBinarySearch rbs(1, listPass);

    //Checks if the search found the search term
    bool findOne = rbs.search();
    if (findOne == true) {
        cout << "true ";
    } else {
        cout << "false ";
    }

    //Prints sorted list
    quick.print();

}
