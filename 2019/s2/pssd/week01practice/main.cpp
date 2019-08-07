#include "DownloadingFiles.hpp"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	vector<string> test32;
	test32.push_back("1 10");
	test32.push_back("1 20");
	test32.push_back("2 40");
	DownloadingFiles test;
	cout << test.actualTime(test32) << endl;

	return 0;
}
