#include <iostream>
using namespace std;

int * readNumbers(int n) 
{
	//Creates dynamic array
	int *j = new int[n];

	//Iterates over array, inputting for each element
	for (int i = 0; i < n; i++)
	{
		cin >> *(j + i);
	}

	//Return the address of the start of the array
	return j;
}

void printNumbers(int * numbers, int length)
{
	//Iterates over array, printing each element and element number
	for (int i = 0; i < length; i++)
	{
		cout << i << " " << *(numbers + i) << endl;
	}

	//Deletes numbers in array
	for (int i = 0; i < length; i++)
	{
		*(numbers + i) = 0;
	}
}

double meanSubArrays(int * numbers, int length)
{
	//Declare required variables
	double sum = 0;
	double test = 0;
	double count = 0;

	//Iterates across array
	for (int i = 0; i < length; i++)
	{
		//Iterates accross array, starting at where outer array is looking
		for (int j = i; j < length; j++)
		{
			//Gets sum of every sub array
			test = test + double(*(numbers + j));
			//Sums every sub array
			sum = sum + test;
			//Counts number of sums
			count++;
		}
		//Clears value of sub array when starting new position
		test = 0;
	}

	//Calculates and prints mean
	double mean = double(sum/count);
	cout << mean << endl;
}