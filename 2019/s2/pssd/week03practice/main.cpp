#include "ElevatorLimit.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(0);
	test32.push_back(2);
	vector<int> test91;
	test91.push_back(1);
	test91.push_back(0);
	ElevatorLimit test;
	vector<int> results = test.getRange(test32,test91,1);

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << " | ";
	}
	cout << endl;

	return 0;
}
