#include "Node.h"
#include "Graph.h"
#include "data.h"
#include "helpers.h"
#include <iostream>
#include <vector>


using namespace std;

/*-----------------------------------------
| Initialises the network (Contructor)
|
| Expected input: data structs containing the initial and change information for the network
|
| This will create nodes objects for each edge, and initialize each node's table to INF.
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
		edges[i]->setKeys(initial.keys);
	}

}

/*-----------------------------------------
| Creates connections between two nodes
|
| Expected Input: The ID's of two edge's which will be connected and their weight
|
| This will run add connection from each edge, pointing to the other edge
| and output to the console the change which is made.
------------------------------------------*/
void Graph::createConnection(int edge1, int edge2, int weight)
{
	edges[edge1]->addConnection(edge2, weight);
	outputTableChange(0,edge1,edge2,edge2,weight);
	edges[edge2]->addConnection(edge1, weight);
	outputTableChange(0,edge2,edge1,edge1,weight);
}

/*-----------------------------------------
| Makes changes to connections
|
| Expected Input: The ID's of two edge's which will be connected and their weight
|
| This will update existing connections with a new weight and then
| output to the console the changes which have been made
------------------------------------------*/
void Graph::modifyConnection(int edge1, int edge2, int weight)
{
	edges[edge1]->changeConnection(edge2, weight);
	outputTableChange(0,edge1,edge2,edge2,weight);
	edges[edge2]->changeConnection(edge1, weight);
	outputTableChange(0,edge2,edge1,edge1,weight);
}

/*-----------------------------------------
| Updates all node's tables
|
| Expected Input: Current working timestep
| Expected Output: Bool indicating if any of the nodes were updated
|
| This temporarily stores the distance tables of all nodes for the timestep
| Then it iterates over all nodes and pushes their tables to their neighbours
------------------------------------------*/
bool Graph::updateNodes(int timeStep, bool poisoned)
{
	//Gets the distance tables for the current timestep from all nodes
	vector< vector< vector< int > > > nodeTables;
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		nodeTables.push_back( edges[i]->getTable() );
	}

	//Iterates over all nodes and recieves tables from their neighbours
	bool updated = false;
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		bool thisUpdate = iterateConnectionUpdates(edges[i]->getId(), nodeTables, timeStep, poisoned);
		if (thisUpdate == true)
		{
			cout << endl;
			updated = true;
		}
	}

	return updated;
}

/*-----------------------------------------
| Update target node's distance table with another given table
|
| Expected Input: Takes the ID of the target node, the current timestep and a vector containing all tables
| Expected Output: Bool indicating a change to the table
|
| This iterates over the neighbours and updates the current node with their tables
------------------------------------------*/
bool Graph::iterateConnectionUpdates(int targetNode, vector< vector< vector< int > > > nodeTables, int timeStep, bool poisoned)
{
	vector<int> neighbours = edges[targetNode]->sortConnections();

	bool updated = false;

	//Iterates over the neighbour's sending them the distance tables
	for (int i = 0; i < (signed)neighbours.size(); i++)
	{
		bool thisUpdate = edges[targetNode]->updateTable( neighbours[i], nodeTables[ neighbours[i] ], timeStep, poisoned );
		if (thisUpdate == true)
		{
			updated = true;
		}
	}

	return updated;
}

/*-----------------------------------------
| Calculate the routing table for each node
|
| Runs routing table calculation on each node
------------------------------------------*/
void Graph::generateRoutingTable()
{
	//Iterates over each node
	for (int i = 0; i < (signed)edges.size(); i++)
	{
		edges[i]->calcRoutingTable();
	}
}

/*-----------------------------------------
| Starts the distance vector algorithm
|
| First creates the connections between each node
| Then updates each node's tables until they converge
| Then updates the weights of the connections which changed
| Then updates each node's tables until they converge again
------------------------------------------*/
void Graph::runDistanceVector(bool poisoned)
{
	//Starting changes to distance tables
	cout << "#START" << endl << endl;
	//Create connections between each edge
	for (int i = 0; i < (signed)setup.weights.size(); i++)
	{
		createConnection(setup.weights[i][0], setup.weights[i][1], setup.weights[i][2]);
	}
	cout << endl;

	//Run node updates until convergent
	int timeStep = 1;
	while ( updateNodes(timeStep, false) )
	{
		cout << endl;
		timeStep++;
	}

	//Initial Routing Table
	cout << "#INITIAL" << endl << endl;
	generateRoutingTable();

	//Changed weights updates to distance table
	cout << "#UPDATE" << endl << endl;

	//Update the connections for each change
	for (int i = 0; i < (signed)change.weights.size(); i++)
	{
		modifyConnection(change.weights[i][0], change.weights[i][1], change.weights[i][2]);
	}
	cout << endl;

	//Run node updates until convergent
	timeStep = 1;
	while ( updateNodes(timeStep, poisoned) )
	{
		cout << endl;
		timeStep++;
	}


	//Post-change Routing Table
	cout << "#FINAL" << endl << endl;
	generateRoutingTable();
}

/*-----------------------------------------
| Output table changes to console
|
| Expected Input: The current timestep, the ID of the node from, the ID of the node traveling to,
| the ID of the node to travel via, and the weight of the total distance
|
| Output to console in the given format
------------------------------------------*/
void Graph::outputTableChange(int timeStep, int from, int to, int via, int weight)
{
	cout << "t=" << timeStep << " distance from " << edges[from]->getKey() << " to ";
	cout << edges[to]->getKey() << " via " << edges[via]->getKey() << " is ";
	//Prints INF if weight is -1
	if (weight >= 0)
	{
		cout << weight << endl;
	}
	else
	{
		cout << "INF" << endl;
	}
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
