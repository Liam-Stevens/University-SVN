#include <iostream>
#include <string>
using namespace std;

int * readNumbers(int n) 
{
	int *j = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *(j + i);
	}
	return j;
}

void dayNames(int *days,int length)
{
	string type;
	for (int i = 0; i < length; i++)
	{
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
		cout << i << " " << *(days + i) << " " << type << endl;
	}
}