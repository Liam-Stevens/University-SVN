#include <iostream>
extern int multiply_if_threes(int[], int);
extern bool is_ascending_multiple_threes(int[], int);
extern int multiply_elements(int integers[], int length);

int main()
{
	int output;
	int array[3] = {3,6,9};

	if (is_ascending_multiple_threes(array, 3) == true)
	{
		output = multiply_if_threes(array, 3);
	}
	else
	{
		output = multiply_elements(array, 3);
	}

	std::cout << output << std::endl;

	return 0;
}