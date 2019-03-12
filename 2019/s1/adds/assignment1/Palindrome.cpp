#include "Palindrome.h"
#include <string>

using namespace std;

palindrome::palindrome(std::string setPhrase)
{
	phrase = setPhrase;
}

void palindrome::setPhrase(std::string setPhrase)
{
	phrase = setPhrase;
}

string palindrome::getPhrase()
{
	return phrase;
}

void palindrome::findLength()
{
	//Uses the end string marker to determine string length
	bool found = false;
	int i = 0;
	while (found == false)
	{
		if (phrase[i] == '\0')
		{
			found = true;
			length = i;
		}
		else
		{
			i++;
		}
	}
}

void palindrome::removeNonLetters()
{
	findLength();
	int movement = 0;
	for(int i = 0; i < length; i++)
	{
		//Filters characters by determining if they are upper or lower case characters
		if(isupper(phrase[i]) || islower(phrase[i]))
		{
			phrase[i-movement] = phrase[i];
		}
		else
		{
			movement++;
		}
	}
	phrase.erase(length-movement,movement);
}

void palindrome::lowerCase()
{
	findLength();
	//Makes characters lower case
	for(int i = 0; i < length; i++)
	{
		phrase[i] = tolower(phrase[i]);
	}
}

bool palindrome::isPalindrome()
{
	findLength();
	//Checks if the string is the same in reverse
	for(int i = 0; i < length; i++)
	{
		if (phrase[i] != phrase[length - 1 - i])
		{
			return false;
		}
	}
	return true;
}
