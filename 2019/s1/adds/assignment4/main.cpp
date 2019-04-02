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

	//Declare outputs
	int output0;
	string output1;
	int output2;
	int output3;

	//Check inputs for errors and do the functions
	if (input[0].find('0') != std::string::npos ||
        input[0].find('1') != std::string::npos ||
        input[0].find('2') != std::string::npos ||
        input[0].find('3') != std::string::npos ||
        input[0].find('4') != std::string::npos ||
        input[0].find('5') != std::string::npos ||
        input[0].find('6') != std::string::npos ||
        input[0].find('7') != std::string::npos ||
        input[0].find('8') != std::string::npos ||
        input[0].find('9') != std::string::npos)
    {
        output0 = atoi (input[0].c_str());
    }
    else
    {
    	output0 = -1;
    }
    if (input[2].find('0') != std::string::npos ||
        input[2].find('1') != std::string::npos ||
        input[2].find('2') != std::string::npos ||
        input[2].find('3') != std::string::npos ||
        input[2].find('4') != std::string::npos ||
        input[2].find('5') != std::string::npos ||
        input[2].find('6') != std::string::npos ||
        input[2].find('7') != std::string::npos ||
        input[2].find('8') != std::string::npos ||
        input[2].find('9') != std::string::npos)
    {
        output2 = atoi (input[2].c_str());
    }
    else
    {
    	output2 = -1;
    }
    if (input[3].find('0') != std::string::npos ||
        input[3].find('1') != std::string::npos ||
        input[3].find('2') != std::string::npos ||
        input[3].find('3') != std::string::npos ||
        input[3].find('4') != std::string::npos ||
        input[3].find('5') != std::string::npos ||
        input[3].find('6') != std::string::npos ||
        input[3].find('7') != std::string::npos ||
        input[3].find('8') != std::string::npos ||
        input[3].find('9') != std::string::npos)
    {
        output3 = atoi (input[3].c_str());
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