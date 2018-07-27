// function to average an array
double average(int array[], int n)
{
	if(n < 1){
		return 0.0;
	} else {
		double sum = 0;
		for (int i = 0; i < n; i++){
			sum = sum + array[i];
		}
		double average = sum/n;
		return average;
	}
}
