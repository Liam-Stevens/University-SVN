#include "NiceOrUgly.hpp"
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

	NiceOrUgly test;
	cout << test.describe("EI?RQQ?A?WWQ?I?QRQ?A?QRQ?I?WQR?A?RWR?E?WQR?E?QRR") << endl;


	return 0;
}
