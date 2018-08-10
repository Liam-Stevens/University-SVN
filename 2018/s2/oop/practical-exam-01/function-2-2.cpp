#include <cmath>

int octal_to_decimal(int octal_digits[], int number_of_digits)
{
	int decimal = 0;
	for (int i = 0; i < number_of_digits; i++)
	{
		decimal = decimal + octal_digits[i]*pow(8,(number_of_digits-i));
	}
	return decimal;
}