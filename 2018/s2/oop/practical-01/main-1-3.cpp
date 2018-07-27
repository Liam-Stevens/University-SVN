#include <iostream>
#include <stdlib.h>

extern int count(int*,int,int);

int main(int argc,char **argv)
{
	int array[6] = {1,2,3,4,5,6};
	int num = count(array, 6, 6);
	std::cout << "There are " << num << " six(es)" << std::endl;
	return 0 ;
}

