#include "Individual.h"
#include <string>

using namespace std;

Individual::Individual(int newLength)
{
	length = newLength;
	string temp(newLength, '0');
	binaryString = temp;
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
	int max = 0;
	int inc = 0;
	bool prev = false;
	for (int i = 0; i < binaryString.length(); i++)
	{
		if(prev == false)
		{
			inc = 0;
		}
		if(binaryString[i] == '1')
		{
			inc++;
			prev = true;
		}
		else
		{
			prev = false;
		}
		if(inc > max)
		{
			max = inc;
		}
	}
	return max;
}

std::string Individual::getString()
{
	return binaryString;
}

int Individual::getBit(int pos)
{
	if (pos <= binaryString.length())
	{
		//Must take 48 because the value is a char
		return binaryString[pos] - 48;
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
	if(binaryString[pos] == '0')
	{
		binaryString[pos] = '1';
	}
	else if (binaryString[pos] == '1')
	{
		binaryString[pos] = '0';
	}
	maxOnes = calcMaxOnes();
}

void Individual::setString(string newString)
{
	binaryString = newString;
	maxOnes = calcMaxOnes();
	length = newString.length();
}
