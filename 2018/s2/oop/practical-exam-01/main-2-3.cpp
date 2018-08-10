#include <iostream>
extern int multiply_if_threes(int[], int);
extern bool is_ascending_multiple_threes(int[], int);
extern int multiply_elements(int integers[], int length);

int main()
{
	//variable to print and array of multiples of three
	int output;
	int array[3] = {3,6,9};

	//checks if the array is in accending order of three
	if (is_ascending_multiple_threes(array, 3) == true)
	{
		//if it is, multiples it in threes
		output = multiply_if_threes(array, 3);
	}
	else
	{
		//if it is not, it multiples all elements
		output = multiply_elements(array, 3);
	}

	//print output
	std::cout << output << std::endl;

	return 0;
}