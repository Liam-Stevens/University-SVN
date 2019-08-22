#include "ChickensAndCows.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ChickensAndCows test;
	vector<int> tester = test.howMany(1,3);
	for (int i = 0; i < 2; i++)
	{
		cout << tester[i] << endl;
	}

	return 0;
}
