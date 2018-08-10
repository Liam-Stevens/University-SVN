#include <iostream>

void printer(int array[10][10])
{
	//iterates over all rows of the matrix
	for (int i = 0; i < 10; i++)
	{
		//iterates over all colums of the matrix
		for (int j = 0; j < 10; j++)
		{
			//outputs each value of the 2D array
			std::cout << array[i][j];

			//seperates each value of the array unless it is the final column
			if (j != 9)
			{
				std::cout << " ";
			}
		}

		//starts a new line after each row has been printed
		std::cout << std::endl;
	}

}