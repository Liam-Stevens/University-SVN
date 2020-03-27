#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include "map.h"

class Graph
{
private:
	std::vector< std::vector<Node *> > nodeMap;

public:
	//Constructor
    Graph();

	//Prepare Nodes
	void constructMap(struct map *);
	void setNodeConnections();
	void printGraph(bool);

	//Helpers
	bool inSet(Node *, std::vector<Node *>);
	std::vector<Node *> expandNode(Node *, std::vector<Node *>);

	//Search Algorithms
	void BFS(int, int, int, int);
	void UCS();
	void ASTAR(bool);

	//Destructor
	~Graph();
};


#endif
