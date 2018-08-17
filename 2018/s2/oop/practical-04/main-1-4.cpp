extern void cpyda(double *,double *,int);

int main() 
{
	double array1[2][2] = { {2.0,2.0}, {2.0,2.0} };
	double array2[2][2];
	double *ptr1 = &array1[0][0], *ptr2 = &array2[0][0];
	cpyda(ptr1,ptr2,4);

	return 0;
}