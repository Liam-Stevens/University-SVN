#include "Node.h"

using namespace std;

Node::Node()
{
	//Does Nothing
}

Node::Node(int newData)
{
	elevation = newData;
}

//Getters
int Node::getElevation()
{
	return elevation;
}

Node * Node::getUp()
{
	return up;
}

Node * Node::getDown()
{
	return down;
}

Node * Node::getLeft()
{
	return left;
}

Node * Node::getRight()
{
	return right;
}

//Setters
void Node::setElevation(int newData)
{
	elevation = newData;
}

void Node::setUp(Node * newPtr)
{
	up = newPtr;
}

void Node::setDown(Node * newPtr)
{
	down = newPtr;
}

void Node::setLeft(Node * newPtr)
{
	left = newPtr;
}

void Node::setRight(Node * newPtr)
{
	right = newPtr;
}
