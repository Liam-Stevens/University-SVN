#include <iostream>
extern int octal_to_decimal(int[], int);

int main()
{

	int octal[3] = {1,2,3};

	std::cout << octal_to_decimal(octal, 3) << std::endl;

	return 0;
}