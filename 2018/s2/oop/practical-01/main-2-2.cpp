#include <iostream>
#include <stdlib.h>

extern int maximum(int*,int);

int main(int argc,char **argv)
{
	int array[5] = {1,2,3,4,5};
	std::cout << maximum(array, 5) << std::endl;
	return 0 ;
}

