#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>

class palindrome
{
protected:
	std::string phrase;
	int length;

public:
	palindrome(std::string setPhrase);
	void setPhrase(std::string setPhrase);
	std::string getPhrase();
	void findLength();
	void removeNonLetters();
	void lowerCase();
	bool isPalindrome();

};

#endif