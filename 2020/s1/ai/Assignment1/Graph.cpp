#include "Node.h"
#include "Graph.h"
#include "map.h"
#include <vector>
#include <iostream>
#include <cstdlib>


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
			temp->setPos(j,i);
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
	for (int i = 0; i < (signed)nodeMap.size(); i++)
	{
		for (int j = 0; j < (signed)nodeMap[0].size(); j++)
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
			if (i == (signed)nodeMap.size() - 1)
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
			if (j == (signed)nodeMap[0].size() - 1)
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
		//cout << "Vector Map: " << endl;
		for (int i = 0; i < (signed)nodeMap.size(); i++)
		{
			for (int j = 0; j < (signed)nodeMap[0].size(); j++)
			{
				if (nodeMap[i][j]->getElevation() == -1)
				{
					cout << "X ";
				}
				else if (nodeMap[i][j]->getPath())
				{
					cout << "* ";
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
		//cout << "Node Map: " << endl;
		Node * ptr;
		ptr = nodeMap[0][0];
		for (int i = 0; i < (signed)nodeMap.size(); i++)
		{
			for (int j = 0; j < (signed)nodeMap[0].size(); j++)
			{

				if (ptr != NULL)
				{
					if (ptr->getElevation() == -1)
					{
						cout << "X ";
					}
					else if (ptr->getPath())
					{
						cout << "* ";
					}
					else
					{
						cout << ptr->getElevation() << " ";
					}

					if (j != (signed)nodeMap[0].size() - 1)
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
			for (int j = 0; j < (signed)nodeMap[0].size()-1; j++)
			{
				if (ptr != NULL)
				{
					ptr = ptr->getLeft();
				}
			}
		}
	}

}

bool Graph::inSet(Node * check, vector<Node *> set)
{
	for (int i = 0; i < (signed)set.size(); i++)
	{
		if (check == set[i])
		{
			return true;
		}
	}
	return false;
}

void Graph::priorityQueue(Node * insertNode, int insertCost, std::vector<Node *> * nodeQueue, std::vector<int> * costQueue)
{

	if (costQueue->size() != 0)
	{
		for (int i = 0; i < (signed)costQueue->size(); i++)
		{
			if ( (*costQueue)[i] > insertCost)
			{
				nodeQueue->insert(nodeQueue->begin()+i, insertNode);
				costQueue->insert(costQueue->begin()+i, insertCost);
				break;
			}
			else if (i == (signed)costQueue->size() - 1)
			{
				nodeQueue->push_back( insertNode );
				costQueue->push_back( insertCost );
				break;
			}
		}
	}
	else
	{
		nodeQueue->push_back( insertNode );
		costQueue->push_back( insertCost );
	}


}

vector<Node *> Graph::expandNode(Node * expand, vector<Node *> set)
{
	if (expand->getUp() != NULL)
	{
		expand->getUp()->insertNode(expand);
		set.push_back( expand->getUp() );
	}

	if (expand->getDown() != NULL)
	{
		expand->getDown()->insertNode(expand);
		set.push_back( expand->getDown() );
	}

	if (expand->getLeft() != NULL)
	{
		expand->getLeft()->insertNode(expand);
		set.push_back( expand->getLeft() );
	}

	if (expand->getRight() != NULL)
	{
		expand->getRight()->insertNode(expand);
		set.push_back( expand->getRight() );
	}

	return set;
}

void Graph::expandNodeCost(Node * expand, int currentCost, std::vector<Node *> * set, std::vector<int> * cost)
{
	int nodeCost = 1;

	if (expand->getUp() != NULL)
	{
		Node * nextNode = expand->getUp();
		nodeCost = 1 + abs(nextNode->getElevation() - expand->getElevation());

		nextNode->insertNode(expand);
		priorityQueue(nextNode, nodeCost, set, cost);
	}

	if (expand->getDown() != NULL)
	{
		Node * nextNode = expand->getDown();
		nodeCost = 1 + abs(nextNode->getElevation() - expand->getElevation());

		nextNode->insertNode(expand);
		priorityQueue(nextNode, nodeCost, set, cost);
	}

	if (expand->getLeft() != NULL)
	{
		Node * nextNode = expand->getLeft();
		nodeCost = 1 + abs(nextNode->getElevation() - expand->getElevation());

		nextNode->insertNode(expand);
		priorityQueue(nextNode, nodeCost, set, cost);
	}

	if (expand->getRight() != NULL)
	{
		Node * nextNode = expand->getRight();
		nodeCost = 1 + abs(nextNode->getElevation() - expand->getElevation());

		nextNode->insertNode(expand);
		priorityQueue(nextNode, nodeCost, set, cost);
	}

}

/*-----------------------------------------
| Search Algorithms
------------------------------------------*/

/*-----------------------------------------
| Bredth First Search
------------------------------------------*/
bool Graph::BFS(int startX, int startY, int endX, int endY)
{
	Node * startNode = nodeMap[startY][startX];
	Node * endNode = nodeMap[endY][endX];

	vector<Node *> closed;
	vector<Node *> fringe;
	fringe.push_back(startNode);

	while(true)
	{

		if (fringe.size() == 0)
		{
			//cout << "No Solution" << endl;
			return false;
		}

		Node * currentNode = fringe[0];
		fringe.erase (fringe.begin());

		if (currentNode == endNode)
		{
			//Goal Return
			currentNode->visited(true);
			//currentNode->printNodes();
			//cout << "Node Found" << endl;
			currentNode->traceNodes();
			return true;
		}

		if (!inSet(currentNode, closed) && currentNode->getElevation() != -1)
		{
			currentNode->visited(true);
			closed.push_back(currentNode);
			fringe = expandNode(currentNode, fringe);
		}
		else
		{
			currentNode->visited(false);
		}
	}
}

/*-----------------------------------------
| Uniform-Cost Search
------------------------------------------*/
bool Graph::UCS(int startX, int startY, int endX, int endY)
{
	Node * startNode = nodeMap[startY][startX];
	Node * endNode = nodeMap[endY][endX];

	vector<Node *> closed;
	vector<Node *> fringe;
	vector<int> cost;

	fringe.push_back(startNode);
	cost.push_back(0);

	while(true)
	{

		if (fringe.size() == 0)
		{
			//cout << "No Solution" << endl;
			return false;
		}

		Node * currentNode = fringe[0];
		int currentCost = cost[0];

		fringe.erase (fringe.begin());
		cost.erase (cost.begin());

		//cout << "[" << currentNode->getX()+1 << "][" << currentNode->getY()+1 << "]" << endl;

		if (currentNode == endNode)
		{
			//Goal Return
			currentNode->visited(true);
			currentNode->traceNodes();
			return true;
		}

		if (!inSet(currentNode, closed) && currentNode->getElevation() != -1)
		{
			currentNode->visited(true);
			closed.push_back(currentNode);
			expandNodeCost(currentNode, currentCost, &fringe, &cost);
		}
		else
		{
			currentNode->visited(false);
		}
	}
}

/*-----------------------------------------
| A* Search
------------------------------------------*/
bool Graph::ASTAR(bool heuristic)
{
	return false;
}

/*-----------------------------------------
| Deletes all nodes in the vector
------------------------------------------*/
Graph::~Graph()
{

	for (int i = 0; i < (signed)nodeMap.size(); i++)
	{
		for (int j = 0; j < (signed)nodeMap[0].size(); j++)
		{
			delete nodeMap[i][j];
		}
	}

}
