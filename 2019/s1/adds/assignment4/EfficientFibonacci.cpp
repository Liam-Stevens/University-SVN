#include "EfficientFibonacci.h"
#include <string>
#include <iostream>

using namespace std;

EfficientFibonacci::EfficientFibonacci()
{
	newCalc = true;
}
	
int EfficientFibonacci::calculate(int num)
{
	if (num - num != 0)
	{
		return -1;
	}
	//Handles creation of fib num storage
	if (newCalc == true)
	{
		fibArray = new int[num+1];

		//For checking if the array has a value
		for (int i = 0; i < num+1; i++)
		{
			fibArray[i] = -1;
		}

		fibNum = 0;
		fibArray[0] = 0;
		fibArray[1] = 1;
		newCalc = false;
	}

	//Checks if the fib number exist
	if (fibArray[num] == -1)
	{
		//Handles calculating fib number
		if (num == 0)
		{
			fibNum = fibNum + 0;
		}
		else if (num == 1)
		{
			fibNum = fibNum + 1;
		}
		else
		{
			calculate(num-1);
			calculate(num-2);
		}
		fibArray[num] = fibNum;
	}
	else
	{
		//If the fib number exists, it will use it
		fibNum = fibNum + fibArray[num];
	}
	
	return fibNum;
}

void EfficientFibonacci::reset()
{
	newCalc = true;
}