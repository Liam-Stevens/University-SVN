#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(1252017);
	test32.push_back(3776329);
	test32.push_back(21140492);
	test32.push_back(5357875);
	test32.push_back(59227052);
	test32.push_back(88302560);
	test32.push_back(344236822);
	test32.push_back(52938928);
	test32.push_back(256182128);
	test32.push_back(321584565);
	test32.push_back(22692247);

	vector<int> test33;
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

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
