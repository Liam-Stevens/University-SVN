#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

extern int sum_if_a_palindrome(int*, int);
extern bool is_a_palindrome(int*, int);
extern int sum_elements(int*, int);

int sum_if_a_palindrome(int integers[], int length)
{
	int sum = 0;
	sum = sum_elements(integers, length);

	if(is_a_palindrome(integers,length) != true) 
	{
		if(sum != -1)
		{
			sum = -2;
		}
	}
	return sum;
}

bool is_a_palindrome(int integers[], int length)
{
	int test[length];
	for(int i = 0; i < length; i++)
	{
		test[i] = integers[length-1-i];
	}
	bool pass = true;
	for(int i = 0; i < length; i++)
	{
		if(test[i] != integers[i])
		{
			pass = false;
		}
	}
	return pass;
}

int sum_elements(int integers[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum = sum + integers[i];
	}
	return sum;
}