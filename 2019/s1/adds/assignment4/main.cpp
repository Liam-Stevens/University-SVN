#include "Reverse.h"
#include "Fibonacci.h"
#include "EfficientFibonacci.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	string line;
	string input[4];
	int inc = 0;

	//Takes inputs
	do {
		cin >> line;
		input[inc] = line;
		inc++;
	}
	while(inc < 4);

	//Create objects
	Reverse test1;
	Fibonacci test2;
	EfficientFibonacci test3;

	//Convert from string to int
	int output0 = atoi (input[0].c_str());
	int output2 = atoi (input[2].c_str());
	int output3 = atoi (input[3].c_str());

	string output1;
	
	//Do the functions
	output0 = test1.reverseDigit(output0);
	output1 = test1.reverseString(input[1]);
	output2 = test2.calculate(output2);
	output3 = test3.calculate(output3);

	//Output and error handling
	
	if (output0 == -1)
	{
		cout << "ERROR";
	}
	else
	{
		cout << output0;
	}
	cout << " ";
	cout << output1;
	cout << " ";
	if (output2 == 0)
	{
		cout << "ERROR";
	}
	else
	{
		cout << output2;
	}
	cout << " ";
	if (output3 == 0)
	{
		cout << "ERROR";
	}
	else
	{
		cout << output3;
	}
	cout << endl;

	return 0;
}