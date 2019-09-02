#include "Barbecue.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(1);

	vector<int> test33;
	test33.push_back(0);

	Barbecue test;
	cout << test.eliminate(2,test32,test33) << endl;


	return 0;
}
