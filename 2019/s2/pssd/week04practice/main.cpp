#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(3);
	test32.push_back(2);
	test32.push_back(5);
	test32.push_back(7);

	vector<int> test33;
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
