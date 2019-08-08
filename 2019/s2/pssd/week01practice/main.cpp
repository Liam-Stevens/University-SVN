#include "AzimuthMonitoring.hpp"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("LEFT");
	test32.push_back("LEFT");
	test32.push_back("RIGHT 90");
	AzimuthMonitoring test;
	cout << test.getAzimuth(test32) << endl;

	return 0;
}
