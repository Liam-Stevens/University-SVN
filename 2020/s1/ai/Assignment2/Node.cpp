#include "Node.h"
#include "data.h"

using namespace std;

Node::Node()
{
	left = NULL;
	right = NULL;
	attribute = -1;
	label = "";
}

//Getters
int Node::getDepth()
{
	return depth;
}

float Node::getSplitValue()
{
	return splitValue;
}

int Node::getAttribute()
{
	return attribute;
}

Node * Node::getLeft()
{
	return left;
}

Node * Node::getRight()
{
	return right;
}

string Node::getLabel()
{
	return label;
}

//Setters
void Node::setDepth(int newDepth)
{
	depth = newDepth;
}

void Node::setSplitValue(float newValue)
{
	splitValue = newValue;
}

void Node::setAttribute(int newAttribute)
{
	attribute = newAttribute;
}

void Node::setLeft(Node * newPtr)
{
	left = newPtr;
}

void Node::setRight(Node * newPtr)
{
	right = newPtr;
}

void Node::setLabel(std::string newLabel)
{
	label = newLabel;
}
