#include "LotteryTicket.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	/*
	vector<int> test32;
	test32.push_back(1);
	test32.push_back(1);
	test32.push_back(2);
	test32.push_back(2);

	vector<int> test33;
	test33.push_back(4);
	test33.push_back(6);*/

	LotteryTicket test;
	cout << test.buy(2,1,5,10,50) << endl;


	return 0;
}
