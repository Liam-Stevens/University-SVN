#include <string>
extern void copy_2d_strings(std::string[][2], std::string[][2], int);

int main()
{
	std::string defined[3][2] = { {"1","2"}, {"3","4"}, {"5","6"} };
	std::string undefined[3][2];
	copy_2d_strings(defined, undefined, 3);
	return 0;
}