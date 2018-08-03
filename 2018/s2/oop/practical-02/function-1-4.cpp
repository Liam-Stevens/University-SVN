#include <iostream>

void print_scaled_matrix(int array[3][3],int scale)
{
	int test[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			test[i][j] = scale*array[i][j];
			std::cout << test[i][j] << " ";
		}
		std::cout << std::endl;
	}
}