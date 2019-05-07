#include "Individual.h"
#include <string>

using namespace std;

Individual::Individual(int newLength)
{
	length = newLength;
	string binaryString(newLength, '0');
	maxOnes = 0;
}

Individual::Individual(std::string newString)
{
	binaryString = newString;
	length = binaryString.length();
	maxOnes = calcMaxOnes();
}

//Rework for intended functionality
int Individual::calcMaxOnes()
{
	int temp = 0;
	for (int i = 0; i < binaryString.length(); i++)
	{
		if (binaryString[i] == 1)
		{
			temp++;
		}
	}
	return temp;
}

std::string Individual::getString()
{
	return binaryString;
}

int Individual::getBit(int pos)
{
	if (pos <= binaryString.length())
	{
		return binaryString[pos];
	}
	else
	{
		return -1;
	}
}

int Individual::getMaxOnes()
{
	return maxOnes;
}

int Individual::getLength()
{
	return length;
}

void Individual::flipBit(int pos)
{
	if(binaryString[pos] == 0)
	{
		binaryString[pos] = 1;
	}
	else if (binaryString[pos] == 1)
	{
		binaryString[pos] = 0;
	}
	maxOnes = calcMaxOnes();
}
