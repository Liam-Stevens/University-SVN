#include "Reverse.h"
#include "Fibonacci.h"
#include "EfficientFibonacci.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

//Checks if the string contains a number
bool checkForNum(string check)
{
	if (check.find('0') != string::npos ||
        check.find('1') != string::npos ||
        check.find('2') != string::npos ||
        check.find('3') != string::npos ||
        check.find('4') != string::npos ||
        check.find('5') != string::npos ||
        check.find('6') != string::npos ||
        check.find('7') != string::npos ||
        check.find('8') != string::npos ||
        check.find('9') != string::npos)
    {
    	return true;
    }
    else
    {
    	return false;
    }
}

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

	//Declare outputs
	int output0;
	string output1;
	int output2;
	int output3;

	//Check inputs for errors and do the functions
	if (checkForNum(input[0]))
    {
        output0 = atoi (input[0].c_str());
        output0 = test1.reverseDigit(output0);
    }
    else
    {
    	output0 = -1;
    }
    if (checkForNum(input[2]))
    {
        output2 = atoi (input[2].c_str());
        output2 = test2.calculate(output2);
    }
    else
    {
    	output2 = -1;
    }
    if (checkForNum(input[3]))
    {
        output3 = atoi (input[3].c_str());
        output3 = test3.calculate(output3);
    }
    else
    {
    	output3 = -1;
    }

	output1 = test1.reverseString(input[1]);


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
	if (output2 == -1)
	{
		cout << "ERROR";
	}
	else
	{
		cout << output2;
	}
	cout << " ";
	if (output3 == -1)
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