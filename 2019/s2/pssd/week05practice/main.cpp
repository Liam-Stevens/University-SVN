#include "Multiples.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	Multiples test;
	cout << test.number(3,{0,1,2,2},{2,2,0,1}) << endl;


	return 0;
}
