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
	test32.push_back("Gamma");
	test32.push_back("Delta");
	test32.push_back("Epsilon");

	LineSpacing test;
	cout << test.adjusted(test32, 32) << endl;


	return 0;
}
