#include "RunLengthEncoding.hpp"
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
	test32.push_back(5);
	test32.push_back(1);
	test32.push_back(6);
	test32.push_back(1);

	/*vector<int> test33;
	test33.push_back(4);
	test33.push_back(1);
	test33.push_back(3);*/

	RunLengthEncoding test;

	cout << test.decode("50A") << endl;


	return 0;
}
