#include <string>
using namespace std;
extern void print_class(string[4],string*,int[][4],int);
extern string input_course(int);
extern int input_num();
extern string input_students(int);
extern int input_score(int);

int main()
{
	string courses[4];
	for (int i = 0; i < 4; i++)
	{
		courses[i] = input_course(i);
	}

	int num_students = input_num();

	string students[num_students];
	for (int i = 0; i < num_students; i++)
	{
		students[i] = input_students(i);
	}

	int report_card[num_students][4];
	for (int i = 0; i < num_students; i++)
	{
		report_card[i][4] = input_score(i);
	}


	print_class(courses,students,report_card,num_students);
	return 0;
}