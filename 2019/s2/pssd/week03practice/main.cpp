#include "ElevatorLimit.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(6);
	test32.push_back(85);
	test32.push_back(106);
	test32.push_back(1);
	test32.push_back(199);
	test32.push_back(76);
	test32.push_back(162);
	test32.push_back(141);
	vector<int> test91;
	test91.push_back(38);
	test91.push_back(68);
	test91.push_back(62);
	test91.push_back(83);
	test91.push_back(170);
	test91.push_back(12);
	test91.push_back(61);
	test91.push_back(114);
	ElevatorLimit test;
	vector<int> results = test.getRange(test32,test91,668);

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << " | ";
	}
	cout << endl;

	return 0;
}
