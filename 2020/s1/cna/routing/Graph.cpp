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
Graph::Graph(struct data initial, struct data update)
{
	setup = initial;
	change = update;

	//Create Nodes for each edge
	for (int i = 0; i < (signed)initial.keys.size(); i++)
	{
		Node * edge;
		edge = new Node(initial.keys[i], i);

		edges.push_back(edge);
	}

	//Initialize the tables with infinites
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		edges[i]->initializeTable( (signed)edges.size() );
	}

}

/*-----------------------------------------
| Creates connections between two nodes
------------------------------------------*/
void Graph::createConnection(int edge1, int edge2, int weight)
{
	edges[edge1]->addConnection(edge2, weight);
	outputTableChange(0,edge1,edge2,edge2,weight);
	edges[edge2]->addConnection(edge1, weight);
	outputTableChange(0,edge2,edge1,edge1,weight);
}

bool Graph::updateNodes()
{
	vector< vector< vector< int > > > nodeTables;
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		nodeTables.push_back( edges[i]->getTable() );
	}
	return 0;
}

/*-----------------------------------------
|
------------------------------------------*/
void Graph::runDistanceVector()
{
	//Starting changes to distance tables
	cout << "#START" << endl << endl;
	//Create connections between each edge
	for (int i = 0; i < (signed)setup.weights.size(); i++)
	{
		createConnection(setup.weights[i][0], setup.weights[i][1], setup.weights[i][2]);
	}
	cout << endl;

	//Initial Routing Table
	cout << "#INITIAL" << endl << endl;
	//TODO: Starting routing table

	//Changed weights updates to distance table
	cout << "#UPDATE" << endl << endl;
	//TODO: Update distance vector

	//Post-change Routing Table
	cout << "#FINAL" << endl << endl;
	//TODO: Update routing table
}

/*-----------------------------------------
|
------------------------------------------*/
bool Graph::nodeDistanceVector()
{
	//TODO: Something
	return 0;
}

void Graph::outputTableChange(int timeStep, int from, int to, int via, int weight)
{
	cout << "t=" << timeStep << " distance from " << edges[from]->getKey() << " to ";
	cout << edges[to]->getKey() << " via " << edges[via]->getKey() << " is " << weight << endl;
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

//Calls all node's print table functions
void Graph::printAllTables()
{
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		edges[i]->printTable();
	}
}

/*-----------------------------------------
| Deletes all nodes in the graph
------------------------------------------*/
Graph::~Graph()
{
	//TODO: delete all the nodes
}
