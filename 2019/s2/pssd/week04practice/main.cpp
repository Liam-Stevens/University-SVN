#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(1999999991);
	test32.push_back(1999999992);
	test32.push_back(1999999993);
	test32.push_back(1999999994);
	test32.push_back(1999999995);
	test32.push_back(1999999996);
	test32.push_back(1999999997);
	test32.push_back(1999999998);
	test32.push_back(1999999999);
	test32.push_back(2000000000);

	vector<int> test33;
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
