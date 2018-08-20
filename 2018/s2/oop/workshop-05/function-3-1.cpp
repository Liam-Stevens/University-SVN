#include <iostream>
#include <string>
using namespace std;

int *readNumbers() 
{
	int *j = new int[10];
	for(int i = 0; i < 10; i++)
	{
		std::cin >> *(j+i);
	}
	return j;
}

void printNumbers(int *numbers,int length) 
{
	for(int i = 0; i < length; i++)
	{
		std::cout << i << " " << *(numbers + i) << std::endl;
	}

	for(int j = 0; j < length; j++)
	{
		*(numbers + j) = 0;
	}
}

void hexDigits(int *numbers,int length) 
{
	for(int i = 0; i < length; i++)
	{
		if (*(numbers + i) < 10)
		{
			cout << i << " " << *(numbers + i) << " " << *(numbers + i) << endl;
		}
		else
		{
			string test;
			switch( *(numbers + i) )
			{
				case 10: test = "A";
				break;
				case 11: test = "B";
				break;
				case 12: test = "C";
				break; 
				case 13: test = "D";
				break;
				case 14: test = "E";
				break;
				case 15: test = "F";
				break;
			}
			cout << i << " " << *(numbers + i) << " " << test << endl;

		}
	}

}

bool equalsArray(int *numbers1,int *numbers2,int length) 
{
	if (length < 1)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if ( *(numbers1 + i) != *(numbers2 + i))
			{
				return false;
			}
		}
		return true;
	}
}