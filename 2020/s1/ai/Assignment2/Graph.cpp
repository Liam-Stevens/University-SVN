#include "Node.h"
#include "Graph.h"
#include "data.h"
#include "helpers.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

Graph::Graph(struct data myData, int minLeaf)
{
	root = createDTL(myData, minLeaf);
}

/*-----------------------------------------
| Contructs the tree
------------------------------------------*/
Node * Graph::createDTL(struct data myData, int minLeaf)
{
	if ((signed)myData.attributes.size() <= minLeaf || checkSame(myData)) //TODO: OR all nums are the same OR all labels are the same
	{
		Node * leaf;
		leaf = new Node;

		int distinct = distinctLabel(myData);
		string label = "unknown";
		if (distinct == 0) //If a single distinct label exists
		{
			label = "AAA";
		}
		else if (distinct == 1)
		{
			label = "AA";
		}
		else if (distinct == 2)
		{
			label = "A";
		}
		else if (distinct == 3)
		{
			label = "BBB";
		}
		else if (distinct == 4)
		{
			label = "BB";
		}
		else if (distinct == 5)
		{
			label = "B";
		}
		else if (distinct == 6)
		{
			label = "CCC";
		}

		//cout << "New Leaf: " << label << endl;
		leaf->setLabel(label);

		return leaf;
	}
	struct splits newSplit;
	chooseSplit(&newSplit, myData);

	//Create node
	Node * temp;
	temp = new Node;
	temp->setAttribute(newSplit.bestAttribute);
	temp->setSplitValue(newSplit.bestSplitValue);

	//Set left and right
	struct data leftData;
	struct data rightData;
	//cout << "Data Points: " << myData.attributes.size() << " | BEST ATTRIBUTE: " << newSplit.bestAttribute << " | BEST SPLIT: " << newSplit.bestSplitValue << endl;
	splitData(newSplit.bestAttribute, newSplit.bestSplitValue, myData, &leftData, &rightData);
	//cout << "LEFT SPLIT: " << leftData.attributes.size() << endl;
	temp->setLeft( createDTL(leftData,minLeaf) );
	//cout << "RIGHT SPLIT: " << rightData.attributes.size() << endl;
	temp->setRight( createDTL(rightData,minLeaf) );

	return temp;
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
			const double multiplier = pow(10.0, 5);
			float splitValue = 0.5*(myData.attributes[j][i] + myData.attributes[j+1][i]);
			splitValue = ceil(splitValue * multiplier) / multiplier;
			float gain = calcGain(myData, i, splitValue);
			//cout << gain << endl;
			if (gain > bestGain)
			{
				bestGain = gain;
				bestSplit->bestSplitValue = splitValue;
				bestSplit->bestAttribute = i;
			}

		}

	}

}

/*-----------------------------------------
| Choose label from tree
------------------------------------------*/
string Graph::predict(vector<float> currentData)
{
	Node * temp = root;
	while (temp->getLeft() != NULL || temp->getRight() != NULL)
	{
		if (currentData[temp->getAttribute()] <= temp->getSplitValue())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	return temp->getLabel();
}

/*-----------------------------------------
| Deletes all nodes in the tree
------------------------------------------*/
Graph::~Graph()
{
	//TODO: delete all the nodes
}
