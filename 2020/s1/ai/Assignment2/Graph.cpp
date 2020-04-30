#include "Node.h"
#include "Graph.h"
#include "data.h"
#include "helpers.h"
#include <iostream>


using namespace std;

Graph::Graph()
{
	root = NULL;
}

/*-----------------------------------------
| Contructs the tree
------------------------------------------*/
void Graph::createDTL(struct data * myData, int minLeaf)
{

}

/*-----------------------------------------
| Chooses the best split
------------------------------------------*/
void Graph::chooseSplit(struct splits * bestSplit, struct data myData)
{
	float bestGain = 0;

	//Do each Attribute
	for (int i = 0; i < 5; i++)
	{
		
		//Sort for attribute
		sortAttribute(&myData, i);

		//Split for the middle of each value (N)
		for (int j = 0; j < (signed)myData.attributes.size() - 1; j++)
		{
			float splitValue = 0.5*(myData.attributes[j][i] + myData.attributes[j+1][i]);
			float gain = calcGain(myData, i, splitValue);
			if (gain > bestGain)
			{
				bestSplit->bestSplitValue = splitValue;
				bestSplit->bestAttribute = i;
			}

		}

	}

}

/*-----------------------------------------
| Choose label from tree
------------------------------------------*/
string Graph::predict(struct data * myData)
{
	return "NULL";
}

/*-----------------------------------------
| Deletes all nodes in the tree
------------------------------------------*/
Graph::~Graph()
{

}
