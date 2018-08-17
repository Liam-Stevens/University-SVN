extern void print_sevens(int *,int);

int main()
{
	int array1[5] = {1,7,3,14,5};
	int *ptr = &array1[0];
	print_sevens(ptr,5);
	return 0;
}