#include "Thimbles.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	vector<string> test32;
	test32.push_back("1-2");
	test32.push_back("3-1");
	/*
	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	Thimbles test;
	cout << test.thimbleWithBall(test32) << endl;


	return 0;
}
