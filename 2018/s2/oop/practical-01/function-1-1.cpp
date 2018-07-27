// function to sum an array
int sum_array(int array[], int n)
{
	if(n < 1) {
		return 0;
	} else {
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum = sum + array[i];
		}
		return sum;
	}
}
