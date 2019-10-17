#include "VeryInterestingMovie.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	vector<string> test32;
	test32.push_back("YYYYYYN");
	test32.push_back("YYYYNYY");
	test32.push_back("NYYYNYY");
	test32.push_back("NYYYYYN");
	test32.push_back("YYYYYYN");
	test32.push_back("NYYNYNY");
	test32.push_back("YYYYYYY");
	/*
	vector<int> test33;
	test33.push_back(2);
	test33.push_back(2);*/

	VeryInterestingMovie test;

	cout << test.maximumPupils(test32) << endl;


	return 0;
}
