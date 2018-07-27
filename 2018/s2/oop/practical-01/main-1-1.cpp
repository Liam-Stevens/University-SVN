#include <iostream>
#include <stdlib.h>

extern int sum_array(int*, int);

int main(int argc,char **argv)
{
	int array[6] = {1,2,3,4,5,6};
	int sum = sum_array(array, 6);
	std::cout << "The sum is: " << sum << std::endl;
	return 0 ;
}

