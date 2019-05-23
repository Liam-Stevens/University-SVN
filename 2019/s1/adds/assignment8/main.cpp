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
	while(cin.peek() != '\n' && inc < 100 && feof(stdin) == false);

    QuickSort quick(input, inc);
    quick.doSort();

    vector<int> listPass = quick.getList();
    RecursiveBinarySearch qs(1, listPass);

    bool findOne = qs.search();
    if (findOne == true) {
        cout << "true ";
    } else {
        cout << "false ";
    }

    quick.print();

}
