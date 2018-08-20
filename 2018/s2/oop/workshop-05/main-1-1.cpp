extern int *readNumbers() ;
extern void printNumbers(int *numbers,int length) ;

int main() 
{
	printNumbers(readNumbers(), 10);
	return 0;
}