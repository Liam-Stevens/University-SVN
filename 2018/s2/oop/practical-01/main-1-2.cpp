#include <iostream>
#include <stdlib.h>

extern double average(int*,int);

int main(int argc,char **argv)
{
	int array[6] = {1,2,3,4,5,6};
	double ave = average(array, 6);
	std::cout << "The average is " << ave << std::endl;
	return 0 ;
}

