#include "SquareOfDigits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	string test24[11] = {"00",
 "11",
 "22",
 "33",
 "45",
 "67",
 "66",
 "77",
 "88",
 "99"};
 test32.assign(test24,test24+11);
	//test32.push_back("42101");
	//test32.push_back("22100");
	//test32.push_back("22101");
	SquareOfDigits test;
	cout << test.getMax(test32) << endl;

	return 0;
}
