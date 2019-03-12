#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;

main()
{
	string line;
	getline(cin,line);
	palindrome test(line);
	test.removeNonLetters();
	test.lowerCase();
	cout << test.getPhrase() << endl;
	cout << test.isPalindrome() << endl;

	return 0;
}