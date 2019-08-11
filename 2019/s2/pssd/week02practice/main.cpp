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
	long r = 653;
	long g = 32;
	long b = 1230;
	long k = 556;
	cout << test.getColor(r, g, b, k) << endl;

	return 0;
}
