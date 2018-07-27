// function to average an array
double average(int array[], int n)
{
	if(n < 1){
		return 0.0;
	} else {
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum = sum + array[i];
		}
		int average = sum/n;
		return average;
	}
}
