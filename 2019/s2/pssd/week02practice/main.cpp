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
	long r = 1362806;
	long g = 9637722;
	long b = 7058502;
	long k = 1977778;
	cout << test.getColor(r, g, b, k) << endl;

	return 0;
}
