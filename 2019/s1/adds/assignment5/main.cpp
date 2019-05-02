#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"
#include "FilterGeneric.h"
#include "FilterOdd.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"

using namespace std;

int main()
{
	//Takes input string
	string line;
	string input[20];
	int inc = 0;
	do {
		cin >> line;
		input[inc] = line;
		inc++;
	}
	while(inc < 20);

	//Converts sample string into integer list
	vector<int> list;
	int filter;
	for (int i = 0; i < 20; i++)
	{
		stringstream(input[i]) >> filter;
		list.push_back(filter);
	}


	//Converts L to L'
	MapTriple triple;
	MapAbsoluteValue absolute;
	list = absolute.map(list);
	list = triple.map(list);

	//Converts L' to L"
	FilterOdd oddNum;
	FilterForTwoDigitPositive twoDigit;
	list = twoDigit.filter(list);
	list = oddNum.filter(list);

	//Computes minimum and GCD
	vector<int> min;
	vector<int> gcd;
	ReduceMinimum findMin;
	ReduceGCD findGCD;
	min = findMin.reduce(list);
	gcd = findGCD.reduce(list);

	//Output
	cout << min[0] << " " << gcd[0] << endl;

	return 0;
}