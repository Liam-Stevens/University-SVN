#include <iostream>
#include <stdlib.h>

extern int minimum(int*,int);

int main(int argc,char **argv)
{
	int array1[5] = {1,2,3,4,5};
	std::cout << minimum(array1,5) << std::endl;
	return 0 ;
}
