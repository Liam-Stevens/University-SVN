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
	vector<int> firstNum;
	vector<int> secondNum;
	int baseNumber = 0;
	int index = 0;
	for (int i = 0; i < elements; i++)
	{
		//Test for integer inside string
		if (isdigit (line[i]))
		{
			if(index == 0)
			{
				firstNum.push_back(line[i]-48);
			} else if (index == 1)
			{
				secondNum.push_back(line[i]-48);
			} else if(index == 2)
			{
				baseNumber = baseNumber * 10;
				baseNumber = baseNumber + line[i] - 48;
			} else {
				break;
			}
		} else {
			//Next number if space detected
			index++;
		}
	}

	//Makes an appropriate space to perform addition
	int maxLength = firstNum.size();
	if (secondNum.size() > maxLength)
	{
		maxLength = secondNum.size();
	}
	maxLength++;
	vector<int> workingFirstNumber = firstNum;
	workingFirstNumber.insert(workingFirstNumber.begin(),0);
	vector<int>	workingSecondNumber = secondNum;
	workingSecondNumber.insert(workingSecondNumber.begin(),0);
	while(workingFirstNumber.size() < workingSecondNumber.size())
	{
		workingFirstNumber.insert(workingFirstNumber.begin(),0);
	}
	while(workingFirstNumber.size() > workingSecondNumber.size())
	{
		workingSecondNumber.insert(workingSecondNumber.begin(),0);
	}
/*
	//Line Checker
	for (int i = 0; i < maxLength; i++)
	{
		cout << workingFirstNumber[i];
	}
	cout << endl;
	for (int i = 0; i < maxLength; i++)
	{
		cout << workingSecondNumber[i];
	}
	cout << endl;*/





	//School Method for Addition
	int sum[maxLength];
	int carry = 0;
	for (int i = maxLength - 1; i >= 0; i--)
	{
		sum[i] = workingFirstNumber[i] + workingSecondNumber[i] + carry;
		//cout << "Num" << i << " | " << sum[i] << endl;
		carry = 0;
		//Makes the carry for the next number
		while (sum[i] >= baseNumber)
		{
			carry = sum[i] / baseNumber;
			sum[i] = sum[i] % baseNumber;
		}
	}
	int cut = 0;
	for (int i = 0; i < maxLength; i++)
	{
		if (sum[i] == 0)
		{
			cut++;
		} else {
			break;
		}
	}



	//Karatsuba Multiplication
	unsigned long long int karatsubaResult = 0;



	//Division for postgraduates only (NOT REQUIRED)
	int divisionResult = 0;

	//Outputs the results
	//Output Addition
	for (int i = 0; i < maxLength; i++)
	{
		if(i >= cut)
		{
			cout << sum[i];
		}
	}
	cout << " ";

	cout << karatsubaResult << " " << divisionResult << endl;


	return 0;
}
