#include <iostream>
#include <stdlib.h>

extern double average(int*,int);

int main(int argc,char **argv)
{
	int array[6] = {1,2,3,4,5,6};
	int average = average(array, 6);
	return 0 ;
}

