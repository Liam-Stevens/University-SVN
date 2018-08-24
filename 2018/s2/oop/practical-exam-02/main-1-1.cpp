extern int * readNumbers(int) ;
extern void printNumbers(int *, int);

int main()
{
	int *j = readNumbers(5);
	printNumbers(j,5);
	return 0;
}