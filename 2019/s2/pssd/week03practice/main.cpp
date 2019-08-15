#include "SquareOfDigits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	string test24[11] = {"9785409507",
 "2055103694",
 "0861396761",
 "3073207669",
 "1233049493",
 "2300248968",
 "9769239548",
 "7984130001",
 "1670020095",
 "8894239889",
 "4053971072"};
 test32.assign(test24,test24+11);
	//test32.push_back("42101");
	//test32.push_back("22100");
	//test32.push_back("22101");
	SquareOfDigits test;
	cout << test.getMax(test32) << endl;

	return 0;
}
