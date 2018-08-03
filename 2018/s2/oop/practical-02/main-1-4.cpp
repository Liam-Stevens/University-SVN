extern void print_scaled_matrix(int[3][3], int);

int main()
{
	int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	print_scaled_matrix(matrix, 4);
	return 0;
}