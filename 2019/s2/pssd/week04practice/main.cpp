#include "MonstersValley2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	vector<int> test32;
	test32.push_back(48219);
	test32.push_back(920898);
	test32.push_back(2179240);
	test32.push_back(9993589);
	test32.push_back(29116629);
	test32.push_back(59158375);
	test32.push_back(61577353);
	test32.push_back(39926727);
	test32.push_back(79239592);
	test32.push_back(92299665);
	test32.push_back(38869806);
	test32.push_back(114951159);
	test32.push_back(224003787);
	test32.push_back(252096248);
	test32.push_back(953956706);
	test32.push_back(626496202);
	test32.push_back(397656017);
	test32.push_back(434784538);
	test32.push_back(1407497740);

	vector<int> test33;
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);
	test33.push_back(1);
	test33.push_back(2);
	test33.push_back(1);

	MonstersValley2 test;
	cout << test.minimumPrice(test32,test33) << endl;


	return 0;
}
