// function to sum even numbers
int count_even(int number)
{
	if(number < 1){
		return 0;
	} else {
		int count = 0;
		if (number % 2 == 0) {
			count = number/2;
		} else {
			count = (number-1)/2;
		}
		return count;
	}
}
