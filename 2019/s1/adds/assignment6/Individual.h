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
	//Constructors
	Individual(int newLength);
	Individual(std::string newString);

	//Getters
	std::string getString();
	int getBit(int pos);
	int getMaxOnes();
	int getLength();

	//Setters
	void flipBit(int pos);
	void setString(std::string newString);
};

#endif
