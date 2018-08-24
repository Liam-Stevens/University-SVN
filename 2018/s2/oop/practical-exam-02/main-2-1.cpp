extern void dayNames(int *,int);
extern int * readNumbers(int) ;

int main()
{
	int *j = readNumbers(5);
	dayNames(j,5);
	return 0;
}