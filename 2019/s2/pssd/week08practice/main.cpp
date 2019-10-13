#include "UnsealTheSafe.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	/*vector<int> test32;
	test32.push_back(7);
	test32.push_back(5);
	test32.push_back(4);
	test32.push_back(3);
	test32.push_back(6);*/
	/*
	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	UnsealTheSafe test;
	for (int i = 2; i < 31; i++)
	{
		cout << i << ": " << test.countPasswords(i) << endl;
	}



	return 0;
}
