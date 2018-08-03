extern void print_summed_matrices(int[3][3], int[3][3]);

int main()
{
	int matrix1[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int matrix2[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	print_summed_matrices(matrix1, matrix2);
	return 0;
}