extern void dayNames(int *,int);
extern int * readNumbers(int) ;

int main()
{
	//Reads numbers and prints corresponding day names
	int *j = readNumbers(5);
	dayNames(j,5);
	return 0;
}