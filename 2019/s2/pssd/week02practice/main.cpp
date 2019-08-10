#include "ChangingString.hpp"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	//vector<string> test32;
	//test32.push_back("LEFT");
	//test32.push_back("LEFT");
	//test32.push_back("RIGHT 90");
	ChangingString test;
	cout << test.distance("ab","ba", 2) << endl;

	return 0;
}
