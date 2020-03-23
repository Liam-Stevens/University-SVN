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

	void constructMap(struct map *);

	void setNodeConnections();

	void printGraph(bool);

	~Graph();
};


#endif
