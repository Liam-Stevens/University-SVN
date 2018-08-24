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

int *swapFirstLast(int *numbers1, int length)
{
	//Creates dynamic array
	int *j = new int[length];

	//Sets the first number of new array to be last number of old array, iterating accross both ways
	*(j) = *(numbers1 + (length - 1));
	*(j + (length - 1)) = *(numbers1);

	//Deletes numbers in array
	for (int i = 0; i < length; i++)
	{
		*(numbers1 + i) = 0;
	}

	//Returns starting address of new array
	return j;
}