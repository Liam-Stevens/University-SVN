#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;
/*
long long karatsuba(long long input1, long long input2, int base)
{

}*/

int main()
{
	//Take the input
	string line;
	getline(cin,line);
	int elements = line.length();

	//Filter string to integer
	long long numbers[3] = {0,0,0};
	int length[3] = {0,0,0};
	int index = 0;
	for (int i = 0; i < elements; i++)
	{
		//Test for integer inside string
		if (isdigit (line[i]))
		{
			numbers[index] = numbers[index] * 10;
			numbers[index] = numbers[index] + line[i] - 48;
			length[index]++;
		} else {
			//Next number if space detected
			index++;
		}
	}
	int baseNumber = numbers[2];


	//Makes an appropriate space to perform addition
	int maxLength = length[0];
	if (length[1] > maxLength)
	{
		maxLength = length[1];
	}
	//Pads 1 extra zero for the highest level sum to go over 9
	maxLength++;

	//Seperate the numbers into a format better suited for the school method
	int firstNum[maxLength];
	int secondNum[maxLength];
	long long workingNumbers[2] = {numbers[0],numbers[1]};
	//Build an array of single digits for the first number
	for (int i = maxLength-1; i >= 0; i--) {
		//Pad the front of the number with 0 if not in the number scope
		if (i < maxLength-length[0])
		{
			//Pads zeros
			firstNum[i] = 0;
		} else {
			//Fill array with number
			firstNum[i] = workingNumbers[0]%10;
			workingNumbers[0] = workingNumbers[0] / 10;
		}
	}
	//Build an array of single digits for the second number
	for (int i = maxLength-1; i >= 0; i--) {
		//Pad the front of the number with 0 if not in the number scope
		if (i < maxLength-length[1])
		{
			//Pads zeros
			secondNum[i] = 0;
		} else {
			//Fill array with number
			secondNum[i] = workingNumbers[1]%10;
			workingNumbers[1] = workingNumbers[1] / 10;
		}
	}




	//School Method for Addition
	int sum[maxLength];
	int carry = 0;
	for (int i = maxLength - 1; i >= 0; i--)
	{
		sum[i] = firstNum[i] + secondNum[i] + carry;
		//Makes the carry for the next number
		while (sum[i] >= baseNumber)
		{
			carry = sum[i] / baseNumber;
			sum[i] = sum[i] % baseNumber;
		}
	}
	//Push sum into a single integer
	long long additionResult = 0;
	for (int i = 0; i < maxLength; i++)
	{
		additionResult = additionResult * 10;
		additionResult = additionResult + sum[i];
	}




	//Karatsuba Multiplication
	long long karatsubaResult = 0;



	//Division for postgraduates only (NOT REQUIRED)
	int divisionResult = 0;

	//Outputs the results
	cout << additionResult << " " << karatsubaResult << " " << divisionResult << endl;


	return 0;
}
