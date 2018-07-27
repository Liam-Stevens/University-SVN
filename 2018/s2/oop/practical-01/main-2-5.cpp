#include <iostream>
#include <stdlib.h>

extern bool descending(int*,int);

int main(int argc,char **argv)
{
	int array[5] = {5,4,3,2,1};
	std::cout << descending(array, 5) << std::endl;
	return 0 ;
}
