#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include "data.h"

class Graph
{
private:
	std::vector< Node * > edges;

public:
	//Constructor
    Graph(struct data, struct data);

	void createConnection(int, int, int);

	void runDistanceVector();
	bool nodeDistanceVector();

	//Debug
	void printNodeKeys();
	void printNodeConnections();

	//Destructor
	~Graph();
};


#endif
