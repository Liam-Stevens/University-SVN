#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "map.h"

using namespace std;

//Forward Declarations
void convertMap(vector<string> mapLines, struct map * myMap);

/*-----------------------------------------
| Verifies the input arguments
------------------------------------------*/
bool verify(int argNum, string mapLocation, string algorithm, string heuristic)
{
	//TODO: Check for map validity (Undure if still needed)

	//Check valid algorithm
	if (algorithm != "bfs" && algorithm != "ucs" && algorithm != "astar")
	{
		return false;
	}

	//Check valid heuristic
	if (algorithm == "astar")
	{
		if (heuristic != "euclidean" && heuristic != "manhattan")
		{
			return false;
		}
	}

	return true;
}

/*-----------------------------------------
| Reads map from file
------------------------------------------*/
bool readMap(string mapLocation, struct map * myMap)
{
	string line;
	vector<string> fileLines;
  	ifstream mapFile (mapLocation.c_str());

	//Open the file
  	if (mapFile.is_open())
  	{
    	while ( getline (mapFile,line) )
    	{
      		fileLines.push_back(line);
    	}
    	mapFile.close();
  	}
	//Unable to open the file
  	else {
		return 1;
	}

	convertMap(fileLines, myMap);

	return 0;
}

/*-----------------------------------------
| Converts the map file to a working format
------------------------------------------*/
void convertMap(vector<string> mapLines, struct map * myMap)
{
	//Store Map size
	stringstream ss1(mapLines[0]);
	ss1 >> myMap->sizeY;
	ss1 >> myMap->sizeX;

	//Store Start position
	stringstream ss2(mapLines[1]);
	ss2 >> myMap->startY;
	ss2 >> myMap->startX;

	//Store End position
	stringstream ss3(mapLines[2]);
	ss3 >> myMap->endY;
	ss3 >> myMap->endX;

	//Store Map
	for (int i = 0; i < myMap->sizeY; i++)
	{
		stringstream ss4(mapLines[3+i]);
		vector<int> temp;

		for (int j = 0; j < myMap->sizeX; j++)
		{
			char hold;
			ss4 >> hold;

			int converter;
			if (hold == 'X')
			{
				converter = -1;
			}
			else
			{
				converter = ( (int)hold ) - 48;
			}

			temp.push_back(converter);
		}

		myMap->view.push_back(temp);
	}
}
