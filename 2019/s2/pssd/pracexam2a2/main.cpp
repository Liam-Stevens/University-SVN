#include "FancyFloor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("-||--||--");
	test32.push_back("--||--||-");
	test32.push_back("|--||--|");
	test32.push_back("||--||--");
	test32.push_back("-||--||--");
	test32.push_back("--||--||-");

	FancyFloor test;
	cout << test.howmanyBoards(test32) << endl;


	return 0;
}
