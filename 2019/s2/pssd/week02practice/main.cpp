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
	long r = 57814135262;
	long g = 46171158951;
	long b = 13343448109;
	long k = 68951653520;
	cout << test.getColor(r, g, b, k) << endl;

	return 0;
}
