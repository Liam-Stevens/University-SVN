#include <iostream>
#include <string>
using namespace std;

int * readNumbers(int n) 
{
	//Creates dynamic array
	int *j = new int[n];

	//Iterates over array, inputting for each element
	for (int i = 0; i < n; i++)
	{
		cin >> *(j + i);
	}

	//Return the address of the start of the array
	return j;
}

void dayNames(int *days,int length)
{
	//Declare an empty string
	string type;

	//Iterates over array
	for (int i = 0; i < length; i++)
	{
		//Sets type to be a day name corresponding to the number
		switch(*(days + i))
		{
			case 0: type = "Mon"; break;
			case 1: type = "Tue"; break;
			case 2: type = "Wed"; break;
			case 3: type = "Thu"; break;
			case 4: type = "Fri"; break;
			case 5: type = "Sat"; break;
			case 6: type = "Sun"; break;
		}

		//Prints the elements, element numbers and corresponding day names
		cout << i << " " << *(days + i) << " " << type << endl;
	}

	//Deletes numbers in array
	for (int i = 0; i < length; i++)
	{
		*(days + i) = 0;
	}
}