#include "Node.h"

Node::Node() {
	//Does Nothing
}

int Node::getData() {
	return data;
}

Node * Node::getPtr() {
	return next;
}

void Node::setData(int newData) {
	data = newData;
}

void Node::setPtr(Node * newPtr) {
	next = newPtr;
}
