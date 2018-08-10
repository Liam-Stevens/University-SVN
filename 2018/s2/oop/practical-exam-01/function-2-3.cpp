#include <cmath>

int multiply_if_threes(int integers[], int length)
{
	if (length <= 0)
	{
		return -1;
	} 
	else 
	{
		int product = integers[0];
		for (int i = 1; i < length; i++)
		{
			product = product*integers[i];
		}
		return product;
	}
}

bool is_ascending_multiple_threes(int integers[], int length)
{
	if (length <= 0)
	{
		return false;
	}
	else
	{
		if (integers[0] % 3 != 0)
		{
			return false;
		}

		for (int i = 1; i < length; i++)
		{
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
	if (length <= 0)
	{
		return -1;
	}
	else
	{
		int product = integers[0];
		for (int i = 1; i < length; i++)
		{
			product = product*integers[i];
		}
		return product;
	}
}