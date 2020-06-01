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

	//Creates connections between two nodes
	void createConnection(int, int, int);

	//Updates all node's tables
	bool updateNodes(int);

	//Update target node's distance table with another given table
	bool iterateConnectionUpdates(int, std::vector< std::vector< std::vector< int > > >, int);

	//
	void generateRoutingTable();

	//Starts the distance vector algorithm
	void runDistanceVector();

	//Output table changes to console
	void outputTableChange(int, int, int, int, int);



	//Debug
	void printNodeKeys();
	void printNodeConnections();
	void printAllTables();

	//Destructor
	~Graph();
};


#endif
