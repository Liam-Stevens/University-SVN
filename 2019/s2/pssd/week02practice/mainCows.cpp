#include "MooingCows.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test1;
	test1.push_back("C..");
	test1.push_back(".C.");
	test1.push_back(".C.");
	vector<string> test2;
	test2.push_back("CCCC");
	test2.push_back("CCCC");
	test2.push_back("CCCC");
	vector<string> test3;
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	test3.push_back("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC");
	vector<string> test4;
	test4.push_back("CCC");
	vector<string> test5;
	test5.push_back("C....");
	test5.push_back("....C");
	test5.push_back("CC...");
	MooingCows test;
	cout << test.dissatisfaction(test1) << endl;
	cout << test.dissatisfaction(test2) << endl;
	cout << test.dissatisfaction(test3) << endl;
	cout << test.dissatisfaction(test4) << endl;
	cout << test.dissatisfaction(test5) << endl;

	return 0;
}
