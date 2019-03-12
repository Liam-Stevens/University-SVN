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
	for(int i = 0; i < length; i++)
	{
		phrase[i] = tolower(phrase[i]);
	}
}

bool palindrome::isPalindrome()
{
	findLength();
	for(int i = 0; i < length; i++)
	{
		if (phrase[i] != phrase[length - 1 - i])
		{
			return false;
		}
	}
	return true;
}
