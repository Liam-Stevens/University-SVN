// function to ...
bool descending(int array[], int n)
{
	if(n < 1){
		return false;
	} else {
		int order = array[0];
		bool pass = true;
		for(int i = 0; i < n; i++){
			if(order <= array[i]){
				pass = false;
			}
		}
		return pass;
	}
}