#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(3843);
	test32.push_back(437808);
	test32.push_back(4088636);
	test32.push_back(21920545);
	test32.push_back(17728351);
	test32.push_back(17282550);
	test32.push_back(111536526);
	test32.push_back(20625035);
	test32.push_back(71882430);
	test32.push_back(129029409);
	test32.push_back(39581290);
	test32.push_back(535389768);
	test32.push_back(749333266);
	test32.push_back(558761224);
	test32.push_back(687500849);
	test32.push_back(1309193142);
	test32.push_back(1247523583);
	test32.push_back(1385101352);

	vector<int> test33;
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(1);

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
