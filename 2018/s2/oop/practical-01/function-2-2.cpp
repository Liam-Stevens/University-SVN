// function to find the maximum
int maximum(int array[], int n)
{
	if(n < 1) {
		return 0;
	} else {
		int max = array[0];
		for(int i=0; i < n; i++){
			if(max < array[i]){
				max = array[i];
			}
		}
		return max;
	}
}
