#include <iostream>
#include <string>
using namespace std;

void hexDigits(int *numbers,int length) 
{
	for(int i = 0; i < length; i++)
	{
		if (*(numbers + i) < 10)
		{
			cout << i << " " << *(numbers + i) << " " << *(numbers + i) << endl;
		}
		else
		{
			string test;
			switch( *(numbers + i) )
			{
				case 10: test = "A";
				break;
				case 11: test = "B";
				break;
				case 12: test = "C";
				break; 
				case 13: test = "D";
				break;
				case 14: test = "E";
				break;
				case 15: test = "F";
				break;
			}
			cout << i << " " << *(numbers + i) << " " << test << endl;

		}
	}

}