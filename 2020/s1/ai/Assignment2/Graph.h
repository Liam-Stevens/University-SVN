#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "data.h"

class Graph
{
private:
	Node * root;

public:
	//Constructor
    Graph();

	//TODO: SOMETHING DESCRIPTIVE
	void createDTL(struct data * myData, int minLeaf);

	void chooseSplit(struct splits * bestSplit, struct data myData);

	std::string predict(struct data * myData);


	//Destructor
	~Graph();
};


#endif
