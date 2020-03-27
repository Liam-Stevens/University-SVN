#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

Node::Node()
{
	path = false;
}

Node::Node(int newData)
{
	elevation = newData;
	path = false;
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

int Node::getX()
{
	return posX;
}

int Node::getY()
{
	return posY;
}

Node * Node::getTrace()
{
	if (previousNodes.size() == 0)
	{
		return NULL;
	}
	else
	{
		return previousNodes[0];
	}
}

bool Node::getPath()
{
	return path;
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

void Node::setPos(int setX, int setY)
{
	posX = setX;
	posY = setY;
}

void Node::setPath(bool newPath)
{
	path = newPath;
}


//Traceback
void Node::insertNode(Node * newNode)
{
	queuedNodes.push_back(newNode);
}

void Node::printNodes()
{
	for (int i = 0; i < (signed)previousNodes.size(); i++)
	{
		cout << "["<< previousNodes[i]->getX()+1 << "]["<< previousNodes[i]->getY()+1 << "], ";
	}
}

void Node::visited(bool visit)
{
	if (visit == false)
	{
		queuedNodes.erase(queuedNodes.begin());
	}
	else
	{
		if (queuedNodes.size() == 0)
		{
			//Starting Location
		}
		else
		{
			previousNodes.push_back(queuedNodes[0]);
			queuedNodes.erase(queuedNodes.begin());
		}
	}
}

void Node::traceNodes()
{
	Node * currentNode = previousNodes[0];
	path = true;

	while(true)
	{
		if (currentNode == NULL)
		{
			break;
		}

		currentNode->setPath(true);
		currentNode = currentNode->getTrace();
	}

}
