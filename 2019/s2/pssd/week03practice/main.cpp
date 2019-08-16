#include "ExerciseMachine.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	//vector<string> test32;
	//test32.push_back("42101");
	//test32.push_back("22100");
	//test32.push_back("22101");
	ExerciseMachine test;
	cout << test.getPercentages("23:59:59") << endl;

	return 0;
}
