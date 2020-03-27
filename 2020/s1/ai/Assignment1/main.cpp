#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Graph.h"
#include "helpers.h"
#include "map.h"

using namespace std;

int main(int argc, char **argv)
{
	string mapLocation = argv[1], algorithm = argv[2], heuristic = "";
	if (argc > 3)
	{
		heuristic = argv[3];
	}

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

	//Construct Map Nodes
	Graph mapGraph;
	mapGraph.constructMap(&myMap);
	//mapGraph.printGraph(false);

	//Do search
	bool print = false;
	if (algorithm == "bfs")
	{
		print = mapGraph.BFS(myMap.startX, myMap.startY, myMap.endX, myMap.endY);
	}
	else if (algorithm == "ucs")
	{
		print = mapGraph.UCS(myMap.startX, myMap.startY, myMap.endX, myMap.endY);
	}
	else if (algorithm == "astar" && heuristic == "")
	{
		print = mapGraph.ASTAR(false);
	}
	else if (algorithm == "astar" && heuristic == "")
	{
		print = mapGraph.ASTAR(true);
	}
	else
	{
		cout << "Argument Error" << endl;
		return 1;
	}

	//Print results
	if (print)
	{
		mapGraph.printGraph(false);
	}
	else
	{
		cout << "null" << endl;
	}


	return 0;
}
