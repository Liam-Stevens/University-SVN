extern int printer(int[10][10]);

int main()
{
	int matrix[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrix[j][i] = 0;
		}
	}
	printer(matrix);

	return 0;
}