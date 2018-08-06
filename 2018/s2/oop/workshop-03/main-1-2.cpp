#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
extern void print_class(string[4],string*,int[][4],int);

int main()
{
	int report_card[4][4] = { {50,67,23,90}, {76,85,59,91}, {98,65,30,51}, {95,89,100,21} };
	string courses[4] = {"Math", "Physics", "English", "Japanese"};
	string students[4] = {"John", "Niki", "Yumi", "Steve"};

	print_class(courses,students,report_card,4);
	return 0;
}