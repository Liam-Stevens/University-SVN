#include "TaliluluCoffee.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	vector<int> test32;
	test32.push_back(27);
	test32.push_back(24);
	test32.push_back(48);
	test32.push_back(27);
	test32.push_back(10);
	test32.push_back(20);
	test32.push_back(35);
	test32.push_back(22);
	test32.push_back(27);
	test32.push_back(26);
	test32.push_back(4);
	test32.push_back(6);
	test32.push_back(32);
	test32.push_back(19);
	test32.push_back(24);
	test32.push_back(37);
	test32.push_back(43);
	/*
	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	TaliluluCoffee test;
	cout << test.maxTip(test32) << endl;


	return 0;
}
