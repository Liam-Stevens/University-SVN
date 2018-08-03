#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

void print_as_binary(std::string decimal_number)
{
	int num = atoi(decimal_number.c_str());
	bool first = true;

	for (int i = 63; i > -1; i--)
	{
		if (num/(pow(2,i)) >= 1)
		{
			num = num - pow(2,i);
			std::cout << "1";
			first = false;
		}
		else
		{
			if (first == false) 
			{
				std::cout << "0";
			}
		}
	}

	std::cout << std::endl;
}