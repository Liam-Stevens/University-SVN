#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int main()
{
	int i = 1;
	int sum = 0;

	while(true)
	{
		if (i-100 > 0)
		{
			break;
		}
		sum = sum + i;
		i++;
	}
	cout << "i: " << i << " sum: " << sum << endl;

	return 0;
}
