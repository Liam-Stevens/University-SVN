#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(7290252);
	test32.push_back(124728206);
	test32.push_back(425327327);
	test32.push_back(980140755);
	test32.push_back(1694076474);


	vector<int> test33;
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
