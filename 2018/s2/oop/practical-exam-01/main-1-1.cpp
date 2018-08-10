extern int printer(int[10][10]);

int main()
{
	//Declares entire matrix to be filled with zeroes
	int matrix[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix[i][j] = 0;
		}
	}

	//calls the printer function
	printer(matrix);

	return 0;
}