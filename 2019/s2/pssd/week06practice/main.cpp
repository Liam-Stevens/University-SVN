#include "BlackAndWhiteSolitaire.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	/*
	vector<string> test32;
	test32.push_back("1 100 100");
	test32.push_back("100 1 100");
	test32.push_back("100 100 1");

	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	BlackAndWhiteSolitaire test;
	cout << test.minimumTurns("BBWBWWBWBWWBBBWBWBWBBWBBW") << endl;


	return 0;
}
