extern int * readNumbers(int) ;
extern void printNumbers(int *, int);

int main()
{
	//Reads in and prints numbers
	int *j = readNumbers(5);
	printNumbers(j,5);
	return 0;
}