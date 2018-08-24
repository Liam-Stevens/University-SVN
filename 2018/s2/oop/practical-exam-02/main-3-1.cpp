extern int *swapFirstLast(int * numbers1, int length);
extern int * readNumbers(int) ;
extern void printNumbers(int *, int);

int main()
{
	int *j = readNumbers(5);
	int *k = swapFirstLast(j,5);
	printNumbers(k,5);
	return 0;
}