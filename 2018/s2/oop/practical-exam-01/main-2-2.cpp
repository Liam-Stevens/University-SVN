#include <iostream>
extern int octal_to_decimal(int[], int);

int main()
{
	//delcares the octal array
	int octal[3] = {1,2,3};

	//calls and prints the result of the octal array converted to decimal
	std::cout << octal_to_decimal(octal, 3) << std::endl;

	return 0;
}