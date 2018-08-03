extern int binary_to_number(int*, int);

int main() 
{
	int binary[30] = {0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,1};
	binary_to_number(binary, 30);
	return 0;
}