#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include "data.h"

class Graph
{
private:
	std::vector< Node * > edges;
	struct data setup;
	struct data change;

public:
	//Constructor
    Graph(struct data, struct data);

	void createConnection(int, int, int);
	bool updateNodes();

	void runDistanceVector();
	bool nodeDistanceVector();

	void outputTableChange(int, int, int, int, int);

	//Debug
	void printNodeKeys();
	void printNodeConnections();
	void printAllTables();

	//Destructor
	~Graph();
};


#endif
