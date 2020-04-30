#include "Node.h"
#include "data.h"

using namespace std;

Node::Node()
{
	left = NULL;
	right = NULL;
}

//Getters
int Node::getDepth()
{
	return depth;
}

float Node::getValue()
{
	return value;
}

float Node::getPoint()
{
	return point;
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
void Node::setDepth(int newDepth)
{
	depth = newDepth;
}

void Node::setValue(float newValue)
{
	value = newValue;
}

void Node::setPoint(float newPoint)
{
	point = newPoint;
}

void Node::setLeft(Node * newPtr)
{
	left = newPtr;
}

void Node::setRight(Node * newPtr)
{
	right = newPtr;
}
