#include <iostream>
#include <string>
#include "human.h"
#include "computer.h"
#include "referee.h"

using namespace std;

int numArgs(string input)
{
	int count = 0;
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == ' ')
		{
			count++;
		}
	}
	return count;
}

bool check(string valid, int num)
{
	if(num = 0)
	{
		return false;
	}
	if(isdigit(valid[0]))
	{
		if(valid[0] != num)
		{
			return false;
		}

		bool forCheck = true;
		for(int i = 0; i < num; i++)
		{
			if(valid[i+3] == 'R' || valid[i+3] == 'P' || valid[i+3] == 'S')
			{

			}
			else
			{
				forCheck = false;
				break;
			}
		}
		if (forCheck = true)
		{
			return true;
		}
	}
	return false;
} 

int main()
{
	bool input = false;
	int args = 0;
	string line;

	while (input == false)
	{
		getline(cin,line);
		args = numArgs(line);
		input = check(line, args);
		if(input = false)
		{
			cout << "Invalid Input, Please enter a Valid Input" << endl;
		}
		else
		{
			input = true;
		}
	}

	human player1(args,line);
	cout << 1;
	computer player2(args);
	cout << 2;
	string *ptr1 = player1.getStrat();
	cout << 3;
	string *ptr2 = player2.getStrat();
	cout << 4;
	referee judge(ptr1,ptr2,args);
	cout << 5;
	judge.compare();
	cout << 6;
	judge.printResults();
	cout << 7;
	cout << endl;

	return 0;
}