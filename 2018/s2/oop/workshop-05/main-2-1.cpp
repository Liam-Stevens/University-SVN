extern void hexDigits(int *numbers,int length) ;

int main()
{
	int array1[10] = {11,12,3,4,15,6,7,8,9,10};
	int *test = &array1[0];
	hexDigits(test, 10);
	return 0;
}