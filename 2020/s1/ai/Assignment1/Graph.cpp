#include "Node.h"
#include "Graph.h"
#include "map.h"
#include <vector>
#include <iostream>


using namespace std;

Graph::Graph()
{
	//Does Nothing
}

/*-----------------------------------------
| Contructs the nodes used in the map
------------------------------------------*/
void Graph::constructMap(struct map * myMap)
{

	for (int i = 0; i < myMap->sizeY; i++)
	{
		vector<Node *> nodeRow;

		for (int j = 0; j < myMap->sizeX; j++)
		{
			Node * temp;
			temp = new Node(myMap->view[i][j]);
			nodeRow.push_back(temp);
		}
		nodeMap.push_back(nodeRow);
	}

	Graph::setNodeConnections();

}

/*-----------------------------------------
| Fixes the links between the nodes
------------------------------------------*/
void Graph::setNodeConnections()
{
	for (int i = 0; i < nodeMap.size(); i++)
	{
		for (int j = 0; j < nodeMap[0].size(); j++)
		{
			//Set Up Ptrs
			if (i == 0)
			{
				nodeMap[i][j]->setUp(NULL);
			}
			else
			{
				nodeMap[i][j]->setUp(nodeMap[i-1][j]);
			}

			//Set Down Ptrs
			if (i == nodeMap.size() - 1)
			{
				nodeMap[i][j]->setDown(NULL);
			}
			else
			{
				nodeMap[i][j]->setDown(nodeMap[i+1][j]);
			}

			//Set Left Ptrs
			if (j == 0)
			{
				nodeMap[i][j]->setLeft(NULL);
			}
			else
			{
				nodeMap[i][j]->setLeft(nodeMap[i][j-1]);
			}

			//Set Right Ptrs
			if (j == nodeMap[0].size() - 1)
			{
				nodeMap[i][j]->setRight(NULL);
			}
			else
			{
				nodeMap[i][j]->setRight(nodeMap[i][j+1]);
			}
		}
	}
}

/*-----------------------------------------
| Prints the Map
------------------------------------------*/
void Graph::printGraph(bool printType)
{
	//Prints using the vector of nodes
	if (printType == false)
	{
		cout << "Vector Map: " << endl;
		for (int i = 0; i < nodeMap.size(); i++)
		{
			for (int j = 0; j < nodeMap[0].size(); j++)
			{
				if (nodeMap[i][j]->getElevation() == -1)
				{
					cout << "X ";
				}
				else
				{
					cout << nodeMap[i][j]->getElevation() << " ";
				}

			}
			cout << endl;
		}
	}
	//Prints using the Node connections
	else
	{
		cout << "Node Map: " << endl;
		Node * ptr;
		ptr = nodeMap[0][0];
		for (int i = 0; i < nodeMap.size(); i++)
		{
			for (int j = 0; j < nodeMap[0].size(); j++)
			{

				if (ptr != NULL)
				{
					if (ptr->getElevation() == -1)
					{
						cout << "X ";
					}
					else
					{
						cout << ptr->getElevation() << " ";
					}

					if (j != nodeMap[0].size() -1)
					{
						ptr = ptr->getRight();
					}

				}

			}
			cout << endl;
			if (ptr != NULL)
			{
				ptr = ptr->getDown();
			}
			for (int j = 0; j < nodeMap[0].size()-1; j++)
			{
				if (ptr != NULL)
				{
					ptr = ptr->getLeft();
				}
			}
		}
	}

}

/*-----------------------------------------
| Deletes all nodes in the vector
------------------------------------------*/
Graph::~Graph()
{

	for (int i = 0; i < nodeMap.size(); i++)
	{
		for (int j = 0; j < nodeMap[0].size(); j++)
		{
			delete nodeMap[i][j];
		}
	}

}
