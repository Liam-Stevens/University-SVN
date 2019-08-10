#include "MooingCows.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("CCCC");
	test32.push_back("CCCC");
	test32.push_back("CCCC");
	test32.push_back("CCCC");
	MooingCows test;
	cout << test.dissatisfaction(test32) << endl;

	return 0;
}
