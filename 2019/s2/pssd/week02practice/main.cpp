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
	long r = 1;
	long g = 1;
	long b = 1;
	long k = 3;
	cout << test.getColor(r, g, b, k) << endl;

	return 0;
}
