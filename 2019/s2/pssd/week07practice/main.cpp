#include "TaliluluCoffee.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	vector<int> test32;
	test32.push_back(7);
	test32.push_back(8);
	test32.push_back(6);
	test32.push_back(9);
	test32.push_back(10);
	/*
	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	TaliluluCoffee test;
	cout << test.maxTip(test32) << endl;


	return 0;
}
