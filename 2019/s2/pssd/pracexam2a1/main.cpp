#include "TalentComp.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(46);
	test32.push_back(70);
	test32.push_back(39);
	test32.push_back(53);
	test32.push_back(10);
	test32.push_back(47);
	test32.push_back(73);
	test32.push_back(95);
	test32.push_back(95);
	test32.push_back(27);
	vector<int> test33;
	test33.push_back(81);
	test33.push_back(47);
	test33.push_back(64);
	test33.push_back(65);
	test33.push_back(34);
	test33.push_back(55);
	test33.push_back(75);
	test33.push_back(16);
	test33.push_back(80);
	test33.push_back(69);

	TalentComp test;
	cout << test.round2(test32,test33) << endl;


	return 0;
}
