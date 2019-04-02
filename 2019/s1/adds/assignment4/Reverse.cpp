#include "Reverse.h"
#include <string>
#include <iostream>

using namespace std;

Reverse::Reverse()
{
	reverse = 0;
}
	
int Reverse::reverseDigit(int value)
{
	//Test for non-negative integer input
	if (value - value == 0)
	{
		if(value >= 0)
		{
			//Base case
			if(value == 0)
			{
				return reverse;
			}
			else
			{
				//Takes the last number and places it at the front of reverse
				remainder = value%10;
	        	reverse = remainder + reverse*10;
	        	value = value / 10;
	        	reverseDigit(value);
	        }
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return reverse;
}

string Reverse::reverseString(string letters)
{
	//Base case
	if (letters.length() > 0)
	{
		//Places the last letter at the front, then recurs without the first letter
		char temp = letters[letters.length()-1];
		letters.erase(letters.length()-1,1);
		newString.push_back(temp);
		reverseString(letters);
	}
	return newString;
}