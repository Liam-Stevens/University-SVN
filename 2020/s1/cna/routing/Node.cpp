#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

/*-----------------------------------------
| Contructors
------------------------------------------*/

Node::Node()
{
    //Nothing
}

Node::Node(string newKey, int newId)
{
    key = newKey;
    id = newId;
}


/*-----------------------------------------
| Setters
------------------------------------------*/

void Node::setKey(string newKey)
{
    key = newKey;
}

void Node::setId(int newId)
{
    id = newId;
}


/*-----------------------------------------
| Getters
------------------------------------------*/

std::string Node::getKey()
{
    return key;
}

int Node::getId()
{
    return id;
}

vector<int> Node::getConnections()
{
    return connections;
}

vector<int> Node::getLocalWeights()
{
    return localWeights;
}

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
|
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

bool Node::updateTable(int tableID, std::vector< std::vector<int> > updateTable)
{
    //If there is no distance table, return
    if ((signed)distanceTable.size() == 0)
    {
        return false;
    }
    bool updated = false;


    for (int i = 0; i < (signed)updateTable.size(); i++)
    {
        if (i != tableID && i != id)
        {
            distanceTable[i][tableID] = distanceTable[tableID][tableID] + getLeastDistance(updateTable[i]);
        }
    }


    return updated;
}

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
| Debug
------------------------------------------*/

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
