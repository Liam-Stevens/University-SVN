#include <iostream>
#include <cmath>

int main()
{
	int binary[] = {0,1,1,0,1,0,1,1};
	int temp[8];

	for (int i=0; i < 8; i++)
	{
		if(i != 0) 
		{
			temp[i] = binary[i-1];
		} else {
			temp[i] = binary[7];
		}
	}

	for (int i=0; i < 8; i++)
	{	
		binary[i] = temp[i];
		std::cout << binary[i];
	}
	std::cout << std::endl;
	return 0;
}