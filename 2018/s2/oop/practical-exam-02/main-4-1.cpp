extern int * readNumbers(int) ;
extern void printNumbers(int *, int);
extern double meanSubArrays(int *, int);

int main()
{
	int *j = readNumbers(3);
	meanSubArrays(j,3);
	return 0;
}