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
	computer player2(args);
	string *ptr1 = player1.getStrat();
	string *ptr2 = player2.getStrat();
	referee judge(ptr1,ptr2,args);
	judge.compare();
	judge.printResults();

	return 0;
}