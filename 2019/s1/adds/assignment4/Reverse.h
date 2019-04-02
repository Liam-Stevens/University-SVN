#ifndef REVERSE_H
#define REVERSE_H

#include <string>

class Reverse
{
private:
	int reverse;
	int remainder;
	std::string newString;

public:
	Reverse();
	
	int reverseDigit(int value);
	std::string reverseString(std::string letters);
};

#endif