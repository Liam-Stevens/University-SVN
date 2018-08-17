#include <string>
#include <iostream>

void copy_2d_strings(std::string first[][2], std::string second[][2], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			second[i][j] = first[i][j];
			std::cout << second[i][j] << " ";
		}
		std::cout << std::endl;
	}
}