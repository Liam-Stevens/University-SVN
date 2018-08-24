extern int *swapFirstLast(int *, int);
extern int * readNumbers(int) ;
extern void printNumbers(int *, int);

int main()
{
	//Reads in an array of numbers
	int *j = readNumbers(5);

	//Swaps number order
	int *k = swapFirstLast(j,5);

	//Prints reversed numbers
	printNumbers(k,5);
	return 0;
}