#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

extern int sum_if_a_palindrome(int*, int);
extern bool is_a_palindrome(int*, int);
extern int sum_elements(int*, int);

int main() 
{
	int pali[5] = { 1,2,3,2,1 };
	std::cout << sum_if_a_palindrome(pali, 5) << std::endl;
}