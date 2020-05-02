#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"
#include "data.h"

class Graph
{
private:
	Node * root;

public:
	//Constructor
    Graph(struct data myData, int minLeaf);

	//TODO: SOMETHING DESCRIPTIVE
	Node * createDTL(struct data myData, int minLeaf);

	void chooseSplit(struct splits * bestSplit, struct data myData);

	std::string predict(std::vector<float> currentData);


	//Destructor
	~Graph();
};


#endif
