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

	//Construct Map Nodes
	Graph mapGraph;
	mapGraph.constructMap(&myMap);
	//mapGraph.printGraph(false);

	//Do search
	if (algorithm == "bfs")
	{
		mapGraph.BFS(myMap.startX, myMap.startY, myMap.endX, myMap.endY);
	}
	else if (algorithm == "ucs")
	{
		mapGraph.UCS();
	}
	else if (algorithm == "astar" && heuristic == "")
	{
		mapGraph.ASTAR(false);
	}
	else if (algorithm == "astar" && heuristic == "")
	{
		mapGraph.ASTAR(true);
	}
	else
	{
		cout << "Argument Error" << endl;
		return 1;
	}

	//Print results
	mapGraph.printGraph(false);

	return 0;
}
