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
}

double meanSubArrays(int * numbers, int length)
{
	double sum = 0;
	double test = 0;
	double count = 0;

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			test = test + double(*(numbers + j));
			sum = sum + test;
			count++;
		}
		test = 0;
	}
	double mean = double(sum/count);
	cout << mean << endl;
}