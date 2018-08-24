extern int * readNumbers(int) ;
extern void printNumbers(int *, int);
extern double meanSubArrays(int *, int);

int main()
{
	int *j = readNumbers(5);
	meanSubArrays(j,5);
	return 0;
}