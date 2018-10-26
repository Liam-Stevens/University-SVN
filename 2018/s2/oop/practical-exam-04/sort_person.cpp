#include "person.h"
#include "sort_person.h"

void sort_person::sort(person **people, int n)
{
	int temp;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//int low = (people[i].get_personID() + i);
			//int high = (people[i].get_personID() + i - 1 + j);
			//if (low < high)
			//{
				//temp = high;
				//high = low;
				//low = temp;
				//*(people.get_personID + i - 1 + j) = low;
				//*(people.get_personID + i) = high
			//}
		}
	}
}