#include "ImportantTasks.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{

	vector<int> test32;
	test32.push_back(5);
	test32.push_back(2);
	test32.push_back(7);
	test32.push_back(8);
	test32.push_back(6);
	test32.push_back(4);
	test32.push_back(2);
	test32.push_back(10);
	test32.push_back(2);
	test32.push_back(3);
	
	vector<int> test33;
	test33.push_back(4);
	test33.push_back(1);
	test33.push_back(3);
	test33.push_back(6);
	test33.push_back(2);
	test33.push_back(10);
	test33.push_back(11);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(3);
	test33.push_back(4);
	test33.push_back(2);

	ImportantTasks test;
	cout << test.maximalCost(test32,test33) << endl;


	return 0;
}
