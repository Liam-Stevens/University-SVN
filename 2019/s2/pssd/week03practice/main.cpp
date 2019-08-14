#include "Arrows.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	//vector<string> test32;
	//test32.push_back("C....");
	//test32.push_back("....C");
	//test32.push_back("CC...");
	Arrows test;
	cout << test.longestArrow("<---") << endl;

	return 0;
}
