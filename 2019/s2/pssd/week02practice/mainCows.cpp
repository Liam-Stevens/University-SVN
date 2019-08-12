#include "MooingCows.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test1;
	test1.push_back("CC....CC........C..");
	test1.push_back("C...........C......");
	test1.push_back(".C.................");
	test1.push_back("..........C........");
	test1.push_back("CCC.........C......");
	test1.push_back(".................C.");
	test1.push_back(".C...C.............");
	test1.push_back("...................");
	test1.push_back(".............C.....");
	test1.push_back(".C.................");
	test1.push_back("......C............");
	test1.push_back("...................");
	test1.push_back("...................");
	test1.push_back("...........C.......");
	test1.push_back("...................");
	MooingCows test;
	cout << test.dissatisfaction(test1) << endl;

	return 0;
}
