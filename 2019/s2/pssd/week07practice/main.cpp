#include "SimpleCompressor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	/*
	vector<int> test32;
	test32.push_back(1);
	test32.push_back(1);
	test32.push_back(2);
	test32.push_back(2);

	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	SimpleCompressor test;
	cout << test.uncompress("[2[2AB]]") << endl;


	return 0;
}
