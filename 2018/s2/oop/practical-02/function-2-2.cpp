#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

int binary_to_number(int binary_digits[], int number_of_digits)
{
	int num = 0;
	int power = number_of_digits - 1;
	for (int i = 0; i < number_of_digits; i++)
	{
		num = num + binary_digits[i]*pow(2,power);
		power--;
	}
	std::cout << num << std::endl;
}