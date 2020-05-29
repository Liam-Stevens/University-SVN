#include "Node.h"
#include "Graph.h"
#include "data.h"
#include "helpers.h"
#include <iostream>
#include <vector>


using namespace std;

/*-----------------------------------------
| Initialises the network (Contructor)
------------------------------------------*/
Graph::Graph(struct data initial, struct data changed)
{
	//Create Nodes for each edge
	for (int i = 0; i < (signed)initial.keys.size(); i++)
	{
		Node * edge;
		edge = new Node(initial.keys[i], i);

		edges.push_back(edge);
	}

	//Create connections between each edge
	for (int i = 0; i < (signed)initial.weights.size(); i++)
	{
		createConnection(initial.weights[i][0], initial.weights[i][1], initial.weights[i][2]);
	}

}

/*-----------------------------------------
| Creates connections between two nodes
------------------------------------------*/
void Graph::createConnection(int edge1, int edge2, int weight)
{
	edges[edge1]->addConnection(edge2, weight);
	edges[edge2]->addConnection(edge1, weight);
}

void runDistanceVector()
{

}

bool nodeDistanceVector()
{
	return 0;
}

/*-----------------------------------------
| Debug
------------------------------------------*/

//Prints out the keys all all nodes
void Graph::printNodeKeys()
{
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		cout << edges[i]->getKey() << " | ";
	}
	cout << endl;
}

//Prints out the neighbours and weights of each node
void Graph::printNodeConnections()
{
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		cout << "Node: " << edges[i]->getKey() << " | Key: " << i << " | " << "Neighbours(Weight): ";
		vector<int> neighbours = edges[i]->getConnections();
		vector<int> weights = edges[i]->getLocalWeights();
		for (int j = 0; j < (signed)neighbours.size(); j++)
		{
			cout << neighbours[j] << "(" << weights[j] << ") ";
		}
		cout << endl;
	}
}

/*-----------------------------------------
| Deletes all nodes in the graph
------------------------------------------*/
Graph::~Graph()
{
	//TODO: delete all the nodes
}
