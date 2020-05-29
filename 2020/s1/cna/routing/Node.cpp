#include <string>
#include "Node.h"

using namespace std;

/*-----------------------------------------
| Contructors
------------------------------------------*/

Node::Node()
{

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
}
