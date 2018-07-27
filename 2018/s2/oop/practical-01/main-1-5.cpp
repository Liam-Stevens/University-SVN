#include <iostream>
#include <stdlib.h>

extern int count_even(int);

int main(int argc,char **argv)
{
	std::cout << count_even(10) << std::endl;
	return 0 ;
}
