#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>

class Individual
{
private:
	int maxOnes;
	int length;
	std::string binaryString;

	int calcMaxOnes();

public:
	Individual(int newLength);
	Individual(std::string newString);

	std::string getString();
	int getBit(int pos);
	int getMaxOnes();
	int getLength();

	void flipBit(int pos);

};

#endif
