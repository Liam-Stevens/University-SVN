#include <iostream>
using namespace std;
int maximum_sum(int *nums,int length)
{
	int largest = 0;
	int test = 0;

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++) {
			test += *(nums + j);
			if (test > largest)
			{
				largest = test;
			}
			
			
		}
		test = 0;
	}
	return largest;
}