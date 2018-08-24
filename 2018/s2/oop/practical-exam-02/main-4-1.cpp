extern int * readNumbers(int) ;
extern void printNumbers(int *, int);
extern double meanSubArrays(int *, int);

int main()
{
	//Reads in numbers and calculates mean of sub arrays
	int *j = readNumbers(3);
	meanSubArrays(j,3);
	return 0;
}