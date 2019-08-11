#include "AlternateColors.hpp"
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
	AlternateColors test;
	long r = 1159652;
	long g = 9711153;
	long b = 312878;
	long k = 1395426;
	cout << test.getColor(r, g, b, k) << endl;

	return 0;
}
