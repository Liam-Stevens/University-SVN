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
	void priorityQueue(Node *, int, std::vector<Node *> *, std::vector<int> *);
	std::vector<Node *> expandNode(Node *, std::vector<Node *>);
	void expandNodeCost(Node *, int, std::vector<Node *> *, std::vector<int> *);

	//Search Algorithms
	bool BFS(int, int, int, int);
	bool UCS(int, int, int, int);
	bool ASTAR(bool);

	//Destructor
	~Graph();
};


#endif
