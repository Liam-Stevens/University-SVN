int identity(int array[10][10])
{
	int pass = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(i == j && array[i][j] != 1) 
			{
				pass = 0;
			}
			else if (i != j & array[i][j] != 0)
			{
				pass = 0;
			}
		}
	}
	return pass;
}