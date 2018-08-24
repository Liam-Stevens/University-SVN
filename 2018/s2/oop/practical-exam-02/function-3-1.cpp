#include <iostream>
using namespace std;

int * readNumbers(int n) 
{
	int *j = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *(j + i);
	}
	return j;
}

void printNumbers(int * numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << i << " " << *(numbers + i) << endl;
	}

	for (int i = 0; i < length; i++)
	{
		*(numbers + i) = 0;
	}
}

int *swapFirstLast(int * numbers1, int length)
{
	int *j = new int[length];
	for (int i = 0; i < length; i++)
	{
		*(j + i) = *(numbers1 + (length - 1) - i);
	}

	for (int i = 0; i < length; i++)
	{
		*(numbers1 + i) = 0;
	}

	return j;
}