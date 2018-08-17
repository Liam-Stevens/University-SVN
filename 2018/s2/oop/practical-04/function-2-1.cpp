#include <iostream>

void print_sevens(int *nums,int length)
{
	for (int i = 0; i < length; i++)
	{
		if ( *(nums + i) % 7 == 0)
		{
			std::cout << *(nums + i) << std::endl;
		}
	}
}