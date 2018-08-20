extern int secondSmallestSum(int *numbers,int length) ;
extern int *reverseArray(int *numbers1,int length) ;
extern bool equalsArray(int *numbers1,int *numbers2,int length) ;
extern void hexDigits(int *numbers,int length) ;
extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main()
{
	int *test1 = readNumbers();
	secondSmallestSum(test1,10) ;
	return 0;
}