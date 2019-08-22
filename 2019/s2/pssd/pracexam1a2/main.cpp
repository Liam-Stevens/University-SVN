#include "Ascending.hpp"
#include <iostream>

using namespace std;

int main()
{
	vector<int> tester;
	tester.push_back(15);
	tester.push_back(15);
	Ascending test;
	cout << test.steps(tester,2) << endl;

	return 0;
}
