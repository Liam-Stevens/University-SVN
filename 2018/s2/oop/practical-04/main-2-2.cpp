extern int maximum_sum(int *,int);

int main()
{
	int array1[10] = { -31, -41, -59, -26, -53, -58, -97, -93, -23, -84 };
	int *ptr = &array1[0];
	maximum_sum(ptr,10);

	return 0;
}