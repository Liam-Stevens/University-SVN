#include <cmath>

int octal_to_decimal(int octal_digits[], int number_of_digits)
{
	//declares the decimal number
	int decimal = 0;

	//iterates over the entire array
	for (int i = 0; i < number_of_digits; i++)
	{
		//takes the decimal number and adds the number in the array multiplied by eight
		//to the power of the highest order power moving to the least significant
		decimal = decimal + octal_digits[i]*pow(8,(number_of_digits-1-i));
	}
	return decimal;
}