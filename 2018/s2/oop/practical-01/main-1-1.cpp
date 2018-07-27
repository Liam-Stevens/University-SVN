#include <iostream>
#include <stdlib.h>

extern int sum_array(int*, int);

int main(int argc,char **argv)
{
	int test[1,2,3,4,5,6];
	sum_array(test[], 6);
	return 0 ;
}

