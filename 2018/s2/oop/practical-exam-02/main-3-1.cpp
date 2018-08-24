extern int *swapFirstLast(int *, int);
extern int * readNumbers(int) ;
extern void printNumbers(int *, int);

int main()
{
	//Reads in an array of numbers
	int *j = readNumbers(10);

	//Swaps number order
	int *k = swapFirstLast(j,10);

	//Prints reversed numbers
	printNumbers(k,10);
	return 0;
}