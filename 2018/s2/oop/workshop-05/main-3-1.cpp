extern bool equalsArray(int *numbers1,int *numbers2,int length) ;
extern void hexDigits(int *numbers,int length) ;
extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main()
{
	int *test1 = readNumbers();
	int *test2 = readNumbers();
	equalsArray(test1,test2,10) ;
	return 0;
}