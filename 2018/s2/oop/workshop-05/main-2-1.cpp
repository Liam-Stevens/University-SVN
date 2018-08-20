extern void hexDigits(int *numbers,int length) ;
extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main()
{
	int array1[10] = {11,12,3,4,15,6,7,8,9,10};
	int *test = readNumbers();
	hexDigits(test, 10);
	return 0;
}