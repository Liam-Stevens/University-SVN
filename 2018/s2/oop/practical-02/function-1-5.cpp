#include <iostream>

void print_summed_matrices(int array1[3][3],int array2[3][3])
{
	int test[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			test[i][j] = array1[i][j] + array2[i][j];
			std::cout << test[i][j] << " ";
		}
		std::cout << std::endl;
	}
}