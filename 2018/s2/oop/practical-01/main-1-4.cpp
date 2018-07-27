#include <iostream>
#include <stdlib.h>

extern int sumtwo(int*,int*,int);

int main(int argc,char **argv)
{
	int array1[6] = {1,2,3,4,5,6};
	int array2[6] = {1,2,3,4,5,6};
	int sum = sumtwo(array1,array2,6);
	std::cout << "The sum is " << sum << std::endl;
	return 0 ;
}
