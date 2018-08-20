#include <iostream>

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
		std::cout << *(numbers + i) << std::endl;
	}

	for(int j = 0; j < length; j++)
	{
		*(numbers + j) = 0;
	}
}