#include <cmath>

int multiply_if_threes(int integers[], int length)
{
	//check if length is zero or negative
	if (length <= 0)
	{
		return -1;
	} 
	else 
	{
		//allows for a non-zero starting multiple
		int product = integers[0];
		for (int i = 1; i < length; i++)
		{
			//will iterate over entire array and multiple every element together
			product = product*integers[i];
		}
		return product;
	}
}

bool is_ascending_multiple_threes(int integers[], int length)
{
	//check if length is zero or negative
	if (length <= 0)
	{
		return false;
	}
	else
	{
		//checks if the first integer is a multiple of three
		if (integers[0] % 3 != 0)
		{
			return false;
		}

		for (int i = 1; i < length; i++)
		{
			//checks if each integer in the array is a multiple of three
			//in reference to the first integer (which checks ascending order aswell)
			if(integers[i] != integers[0] + i*3)
			{
				return false;
			}
		}
		return true;
	}
}

int multiply_elements(int integers[], int length)
{
	//check if length is zero or negative
	if (length <= 0)
	{
		return -1;
	}
	else
	{
		//allows for a non-zero starting multiple
		int product = integers[0];
		for (int i = 1; i < length; i++)
		{
			//will iterate over entire array and multiple every element together
			product = product*integers[i];
		}
		return product;
	}
}