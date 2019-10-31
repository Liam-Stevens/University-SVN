#include "LineSpacing.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("A");
	test32.push_back("quick");
	test32.push_back("brown");
	test32.push_back("fox");
	test32.push_back("jumps");
	test32.push_back("over");
	test32.push_back("the");
	test32.push_back("lazy");
	test32.push_back("dog");

	LineSpacing test;
	cout << test.adjusted(test32, 50) << endl;


	return 0;
}
