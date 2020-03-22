#include <iostream>
#include <string>
#include <vector>
#include "helpers.h"
#include "map.h"

using namespace std;

int main(int argc, char **argv)
{
	string mapLocation = argv[1], algorithm = argv[2], heuristic = argv[3];
	if ( !verify(argc, mapLocation, algorithm, heuristic) )
	{
		cout << "Invalid Arguments" << endl;
		return 1;
	}

	struct map myMap;
	if ( readMap(mapLocation, &myMap) )
	{
		cout << "Cannot Read Map" << endl;
		return 1;
	}

	//Read out map
	cout << myMap.sizeY << " " << myMap.sizeX << endl;
	cout << myMap.startY << " " << myMap.startX << endl;
	cout << myMap.endY << " " << myMap.endX << endl;

	for (int i = 0; i < myMap.sizeY; i++)
	{

		for (int j = 0; j < myMap.sizeX; j++)
		{
			if (myMap.view[i][j] == -1)
			{
				cout << "X ";
			}
			else
			{
				cout << myMap.view[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
