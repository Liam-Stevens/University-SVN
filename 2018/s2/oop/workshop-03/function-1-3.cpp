#include <iostream>
#include <string>
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
			cout << report_card[i][j];
			if (j != 3)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

string input_course(int num)
{
	string course;
	cout << "Please enter the name of course " << num + 1 << endl;
	cin >> course;
	cout << endl;
	return course;
}

int input_num()
{
	int num = 0;
	cout << "Please enter the number of students enrolled" << endl;
	cin >> num;
	return num;
}

string input_students(int num)
{
	cout << "Please enter the name of student " << num << endl;
	return "null";
}

int input_score(int num)
{
	return 0;
}