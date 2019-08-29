#include "TimeTravellingCellar.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(1);
	test32.push_back(2);
	test32.push_back(3);

	vector<int> test33;
	test33.push_back(3);
	test33.push_back(1);
	test33.push_back(2);

	TimeTravellingCellar test;
	cout << test.determineProfit(test32,test33) << endl;


	return 0;
}
