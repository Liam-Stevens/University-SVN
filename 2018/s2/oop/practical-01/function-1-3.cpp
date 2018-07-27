// function to count a certain num in array
int count(int array[], int n, int num)
{
	if(n < 1){
		return 0;
	} else {
		int count = 0;
		for(int i = 0; i < n; i++){
			if(array[i] == num) {
				count++;
			}
		}
		return count++;
	}
}
