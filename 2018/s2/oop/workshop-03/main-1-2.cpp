#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
extern void print_class(string[4],string*,int[][4],int);

int main()
{
	int report_card[4][4];
	string courses[4] = {"Math", "Physics", "English", "Japanese"};
	string students[4] = {"John", "Niki", "Yumi", "Steve"};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			report_card[j][i] = rand() % 100 + 50;
		}
	}

	print_class(courses,students,report_card,4);
	return 0;
}