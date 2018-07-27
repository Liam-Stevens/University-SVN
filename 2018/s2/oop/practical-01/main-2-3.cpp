#include <iostream>
#include <stdlib.h>

extern void twofivenine(int*,int);

int main(int argc,char **argv)
{
	int array[10] = {1,2,2,2,3,4,5,5,8,9};
	twofivenine(array,10);
	return 0 ;
}
