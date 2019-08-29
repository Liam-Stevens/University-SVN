#include "Barbecue.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(0);
	test32.push_back(1);
	test32.push_back(2);
	test32.push_back(2);

	vector<int> test33;
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(0);
	test33.push_back(1);

	Barbecue test;
	cout << test.eliminate(3,test32,test33) << endl;


	return 0;
}
