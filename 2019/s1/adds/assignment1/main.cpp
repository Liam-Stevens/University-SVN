#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

int main()
{
	string line;
	getline(cin,line);
	palindrome test(line);
	test.removeNonLetters();
	test.lowerCase();
	if (test.isPalindrome() == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}