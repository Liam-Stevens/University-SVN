#include "MooingCows.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("C..");
	test32.push_back(".C.");
	test32.push_back(".C.");
	MooingCows test;
	cout << test.dissatisfaction(test32) << endl;

	return 0;
}
