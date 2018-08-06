#include <iostream>
#include <cmath>
using namespace std;

void print_class(string courses[4],string students[],int report_card[][4],int nstudents)
{
	cout << "Report Card ";
	for (int j = 0; j < 4; j++)
	{
		cout << courses[j];
		if (j != 3)
		{
			cout << " ";
		}
	}
	cout << endl;

	for (int i = 0; i < nstudents; i++)
	{
		cout << students[i] << " ";
		for (int j = 0; j < 4; j++)
		{
			cout << report_card[j][i];
			if (j != 3)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}