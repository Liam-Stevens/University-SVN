#include "Fibonacci.h"
#include <string>
#include <iostream>

using namespace std;

Fibonacci::Fibonacci()
{
	fibNum = 0;
}
	
int Fibonacci::calculate(int num)
{
	if (num - num != 0)
	{
		return -1;
	}
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
	return fibNum;
}