#include <string>
#include "sort_int.h"

using namespace std;

void sort_int::sort (int *numbers, int n)
{
	int temp;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(numbers + i) < *(numbers + i - 1 + j))
			{
				temp = *(numbers + i - 1 + j);
				*(numbers + i - 1 + j) = *(numbers + i);
				*(numbers + i) = temp;
			}
		}
	}

}