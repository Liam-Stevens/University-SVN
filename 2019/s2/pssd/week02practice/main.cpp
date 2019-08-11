#include "DerivativeSequence.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(5);
	test32.push_back(6);
	test32.push_back(3);
	test32.push_back(9);
	test32.push_back(-1);
	DerivativeSequence test;
	int reduce = 4;
	vector<int> array(test32.size()-reduce);
	array = test.derSeq(test32,reduce);

	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " | ";
	}
	cout << endl;

	return 0;
}
