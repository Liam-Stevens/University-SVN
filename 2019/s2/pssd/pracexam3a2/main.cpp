#include "LineSpacing.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("Alpha");
	test32.push_back("Beta");
	test32.push_back("John");
	test32.push_back("said");

	LineSpacing test;
	cout << test.adjusted(test32, 29) << endl;


	return 0;
}
