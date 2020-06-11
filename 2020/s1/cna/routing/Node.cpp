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
|
| Expected Input: ID for connected edge and weight of connection
|
| Pushes the connected edge ID to connections and the weight of the
| connection to localWeights, then adds the weight to the distance table
------------------------------------------*/
void Node::addConnection(int connectedEdge, int weight)
{
    connections.push_back(connectedEdge);
    localWeights.push_back(weight);
    distanceTable[ connections.back() ][ connections.back() ] = localWeights.back();
}

/*-----------------------------------------
| Modifies the weight of a connection (or creates new ones if one does not exist)
|
| Expected Input: ID for connected edge and weight of connection
|
| Changes the weight of the edge with ID and changes the weight on the distance table
| If there is no edge with the supplied ID, it will create a connection.
------------------------------------------*/
void Node::changeConnection(int connectionID, int weight)
{
    int index = -1;
    for (int i = 0; i < (signed)connections.size(); i++)
    {
        if (connections[i] == connectionID)
        {
            index = i;
        }
    }

    if (index >= 0)
    {
        localWeights[index] = weight;
        distanceTable[ connections[index] ][ connections[index] ] = weight;
    }
    else
    {
        addConnection(connectionID, weight);
    }

}

/*-----------------------------------------
| Initializes the whole table to INF
|
| Expected Input: the number of edges in the network
|
| Creates an NxN table with all values initialized to -1
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
|
| Expected Input: ID of the supplied table, a 2D vector of the supplied table, and the current timestep
| Expected Output: Bool indicating a change to the table
|
| Creates a copy of this edge's table, applies the distance vector relationship
| then sets the current edge's table if there were changes
------------------------------------------*/
bool Node::updateTable(int tableID, vector< vector<int> > updateTable, int timestep, bool poisoned)
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
        bool prevented = false;

        //Poison the table
        if (poisoned == true)
        {
            int leastID = getLeastDistID(updateTable[i]);
            //Poisons if the ID of the smallest distance in the table points to this Node
            if (i != tableID && i != id && distance != -1 && leastID == id)
            {
                tempTable[i][tableID] = -1;
                prevented = true;
            }
        }

        //Change the value in the table (skipped if successfully poisoned)
        if (i != tableID && i != id && distance != -1 && !prevented)
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
|
| Runs routing calculation to each node (other than itself) from this one
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
|
| Expected Input: the ID of the node to calculate the distance to
|
| First calculates the max in the target node's row and then calcs the min from that max
| (The code from min and max has to be used manually such that I can track the ID of the min and max)
| Then the target node, min value and id of the node to go via is given to outputRoutingLine
------------------------------------------*/
void Node::routeFor(int targetNode)
{
    //Finds minimum distance, but also saves the ID of the node to get to it
    int min = getLeastDistance(distanceTable[targetNode]);
    int viaID = getLeastDistID(distanceTable[targetNode]);

    //Output to console
    outputRoutingLine(targetNode, min, viaID);
}

/*-----------------------------------------
| Finds the minimum number in a vector (excluding -1)
|
| Expected Input: Vector of distances
| Expected Output: the lowest value in the vector
|
| Gets the max value in the vector to then find the min value (excluding -1)
------------------------------------------*/
int Node::getLeastDistance(std::vector<int> distances)
{
    int min = findMax(distances);

    for (int i = 0; i < (signed)distances.size(); i++)
    {
        //Excludes -1
        if (distances[i] < min && distances[i] != -1)
        {
            min = distances[i];
        }
    }

    return min;
}

/*-----------------------------------------
| Finds the column ID for the minimum distance in the vector
|
| Expected Input: Vector of distances
| Expected Output: the ID for the lowest value in the vector
|
| Simple min calculation
------------------------------------------*/
int Node::getLeastDistID(std::vector<int> distances)
{
    int min = findMax(distances);
    int ID = findMaxDistID(distances);

    for (int i = 0; i < (signed)distances.size(); i++)
    {
        //Excludes -1
        if (distances[i] < min && distances[i] != -1)
        {
            ID = i;
            min = distances[i];
        }
    }

    return ID;
}

/*-----------------------------------------
| Finds the maximum number in a vector
|
| Expected Input: Vector of distances
| Expected Output: the highest value in the vector
|
| Simple max calculation
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
| Finds the column ID for the maximum distance in the vector
|
| Expected Input: Vector of distances
| Expected Output: the ID for the highest value in the vector
|
| Simple max calculation
------------------------------------------*/
int Node::findMaxDistID(std::vector<int> distances)
{
    int max = distances[0];
    int ID = 0;

    for (int i = 0; i < (signed)distances.size(); i++)
    {
        if (distances[i] > max)
        {
            ID = i;
            max = distances[i];
        }
    }

    return ID;
}

/*-----------------------------------------
| Checks if two tables are different
|
| Expected Input: takes two 2D vectors of distance tables, and the current timestep
| Expected Output: Bool indicating a change to the table
|
| Compares the two tables and calls outputTableChange on the values which are different
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
|
| Expected Input: the current timestep, the ID of node from, the ID of node to, the ID of node to go via, and the distance
|
| Output to console in the given format
------------------------------------------*/
void Node::outputTableChange(int timeStep, int from, int to, int via, int weight)
{
	cout << "t=" << timeStep << " distance from " << keyList[from] << " to ";
	cout << keyList[to] << " via " << keyList[via] << " is ";
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
| Output routing table line to console
|
| Expected Input: the ID of to node, the ID of node to go via, the distance of the connection
|
| Output to console in the given format
------------------------------------------*/
void Node::outputRoutingLine(int to, int weight, int via)
{
    cout << "router " << key << ": " << keyList[to] << " is ";
    //Prints INF if weight is -1
    if (weight >= 0)
    {
        cout << weight;
    }
    else
    {
        cout << "INF";
    }
    cout << " routing through " << keyList[via] << endl;
}

/*-----------------------------------------
| Bubble sort connection vector
|
| Expected Output: sorted vector (from lowest to highest)
|
| Sorts the IDs of the connections from this node
------------------------------------------*/
vector<int> Node::sortConnections()
{
    vector<int> sorting = connections;

    //Don't need to sort if only 1 value
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
