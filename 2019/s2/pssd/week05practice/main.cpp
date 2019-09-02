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
	test32.push_back(5);
	test32.push_back(3);
	test32.push_back(1);
	test32.push_back(3);
	test32.push_back(5);
	test32.push_back(7);
	test32.push_back(3);
	test32.push_back(5);
	test32.push_back(1);
	test32.push_back(3);
	test32.push_back(5);
	test32.push_back(5);
	test32.push_back(7);
	test32.push_back(5);
	test32.push_back(3);
	test32.push_back(1);
	test32.push_back(3);
	test32.push_back(5);
	test32.push_back(3);
	test32.push_back(7);
	test32.push_back(5);
	test32.push_back(1);
	test32.push_back(7);
	test32.push_back(3);
	test32.push_back(3);
	test32.push_back(5);
	test32.push_back(3);
	test32.push_back(7);
	test32.push_back(7);
	test32.push_back(1);
	test32.push_back(3);


	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);
	test33.push_back(2);
	test33.push_back(7);
	test33.push_back(8);
	test33.push_back(9);
	test33.push_back(1);
	test33.push_back(5);
	test33.push_back(0);
	test33.push_back(0);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(6);
	test33.push_back(3);
	test33.push_back(0);
	test33.push_back(8);
	test33.push_back(9);
	test33.push_back(8);
	test33.push_back(6);
	test33.push_back(4);
	test33.push_back(4);
	test33.push_back(3);
	test33.push_back(9);
	test33.push_back(12);
	test33.push_back(10);
	test33.push_back(7);
	test33.push_back(15);
	test33.push_back(17);
	test33.push_back(0);
	test33.push_back(9);
	test33.push_back(17);

	Barbecue test;
	cout << test.eliminate(20,test32,test33) << endl;


	return 0;
}
