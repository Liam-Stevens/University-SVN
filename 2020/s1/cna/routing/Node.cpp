#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

/*-----------------------------------------
| Contructors
------------------------------------------*/

//Construct node with Key and ID
Node::Node(string newKey, int newId)
{
    key = newKey;
    id = newId;
}


/*-----------------------------------------
| Setters
------------------------------------------*/

//Set the Key of the current node
void Node::setKey(string newKey)
{
    key = newKey;
}

//Set the ID of the current node
void Node::setId(int newId)
{
    id = newId;
}

//Set list of keys of all nodes
void Node::setKeys(std::vector<std::string> newKeys)
{
    keyList = newKeys;
}


/*-----------------------------------------
| Getters
------------------------------------------*/

//Returns the Key of the current node
std::string Node::getKey()
{
    return key;
}

//Returns the ID of the current node
int Node::getId()
{
    return id;
}

//Returns the ids of the connected nodes
vector<int> Node::getConnections()
{
    return connections;
}

//Returns the weights of connected nodes
vector<int> Node::getLocalWeights()
{
    return localWeights;
}

//Returns the distance table
std::vector< std::vector<int> > Node::getTable()
{
    return distanceTable;
}

/*-----------------------------------------
| Functions
------------------------------------------*/

/*-----------------------------------------
| Adds a neighbour and weight of the connection
------------------------------------------*/
void Node::addConnection(int connectedEdge, int weight)
{
    connections.push_back(connectedEdge);
    localWeights.push_back(weight);
    distanceTable[ connections.back() ][ connections.back() ] = localWeights.back();
}

/*-----------------------------------------
| Initializes the whole table to INF
------------------------------------------*/
void Node::initializeTable(int totalNodes)
{
    vector<int> tableRow;
    for (int i = 0; i < totalNodes; i++)
    {
        tableRow.push_back(-1);
    }
    for (int i = 0; i < totalNodes; i++)
    {
        distanceTable.push_back(tableRow);
    }

}

/*-----------------------------------------
| Update this node table with another node's table
------------------------------------------*/
bool Node::updateTable(int tableID, vector< vector<int> > updateTable, int timestep)
{
    //If there is no distance table, return
    if ((signed)distanceTable.size() == 0)
    {
        return false;
    }
    bool updated = false;
    std::vector< std::vector<int> > tempTable = distanceTable;

    //Iterates over each row of the table
    for (int i = 0; i < (signed)updateTable.size(); i++)
    {
        //Ignores the row and column for this table and the connected table
        int distance = getLeastDistance(updateTable[i]);
        if (i != tableID && i != id && distance != -1)
        {
            tempTable[i][tableID] = distanceTable[tableID][tableID] + distance;
        }
    }

    //Checks if the table changed
    if ( differentTables(distanceTable,tempTable, timestep) )
    {
        updated = true;
        distanceTable = tempTable;
    }

    return updated;
}

/*-----------------------------------------
| Calculate the route to each other node
------------------------------------------*/
void Node::calcRoutingTable()
{
    for (int i = 0; i < (signed)distanceTable.size(); i++)
    {
        //Only calculates routes to nodes other than itself
        if (i != id)
        {
            routeFor(i);
        }
    }
    cout << endl;
}

/*-----------------------------------------
| Calculate route to a specific node
------------------------------------------*/
void Node::routeFor(int targetNode)
{
    //TODO: remove magic numbers
    int min = 9999;
    int viaID = 0;

    //Finds minimum distance, but also saves the ID of the node to get to it
    for (int j = 0; j < (signed)distanceTable[targetNode].size(); j++)
    {
        if (distanceTable[targetNode][j] < min && distanceTable[targetNode][j] != -1)
        {
            min = distanceTable[targetNode][j];
            viaID = j;
        }
    }

    //Output to console
    outputRoutingLine(targetNode, min, viaID);
}

/*-----------------------------------------
| Finds the minimum number in a vector (excluding -1)
------------------------------------------*/
int Node::getLeastDistance(std::vector<int> distances)
{
    int min = findMax(distances);

    for (int i = 0; i < (signed)distances.size(); i++)
    {
        if (distances[i] < min && distances[i] != -1)
        {
            min = distances[i];
        }
    }

    return min;
}

/*-----------------------------------------
| Finds the maximum number in a vector
------------------------------------------*/
int Node::findMax(std::vector<int> distances)
{
    int max = distances[0];

    for (int i = 0; i < (signed)distances.size(); i++)
    {
        if (distances[i] > max)
        {
            max = distances[i];
        }
    }

    return max;
}

/*-----------------------------------------
| Checks if two tables are different
------------------------------------------*/
bool Node::differentTables(std::vector< std::vector<int> > comparison1, std::vector< std::vector<int> > comparison2, int timestep)
{
    bool different = false;
    for (int i = 0; i < (signed)comparison1.size(); i++)
    {
        for (int j = 0; j < (signed)comparison1[0].size(); j++)
        {
            //Doesn't check direct connections
            if (comparison1[i][j] != comparison2[i][j])
            {
                outputTableChange(timestep,id,i,j,comparison2[i][j]);
                different = true;
            }
        }
    }

    return different;
}

/*-----------------------------------------
| Output table changes to console
------------------------------------------*/
void Node::outputTableChange(int timeStep, int from, int to, int via, int weight)
{
	cout << "t=" << timeStep << " distance from " << keyList[from] << " to ";
	cout << keyList[to] << " via " << keyList[via] << " is " << weight << endl;
}

void Node::outputRoutingLine(int to, int weight, int via)
{
    cout << "router " << key << ": " << keyList[to] << " is " << weight << " routing through " << keyList[via] << endl;
}

/*-----------------------------------------
| Bubble sort connection vector
------------------------------------------*/
vector<int> Node::sortConnections()
{
    vector<int> sorting = connections;

    if ((signed)sorting.size() > 1)
    {


        bool sorted;
        //Runs until vector is sorted
        do
        {
            sorted = true;
            //Iterates over connection vector
            for(int i = 0; i < (signed)(sorting.size() - 1); i++)
            {
                if (sorting[i] > sorting[i+1])
                {
                    //Swap elements
                    int tmp = sorting[i];
                    sorting[i] = sorting[i+1];
                    sorting[i+1] = tmp;
                    sorted = false;
                }
            }

        }
        while(sorted != true);
    }

    return sorting;
}

/*-----------------------------------------
| Debug
------------------------------------------*/

//Prints the distance table of this node to console
void Node::printTable()
{
    cout << key << " Table" << endl;
    for (int i = 0; i < (signed)distanceTable.size(); i++)
    {
        for (int j = 0; j < (signed)distanceTable.size(); j++)
        {
            cout << distanceTable[i][j] << " | ";
        }
        cout << endl;
    }

}
