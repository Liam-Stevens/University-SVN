#ifndef NODE_H
#define NODE_H

#include "data.h"
#include <string>

class Node
{
private:
	int depth;
	float splitValue;
	int attribute;
	Node * left;
    Node * right;
	std::string label;

public:
	//Constructor
    Node();

	//Getters
	int getDepth();
	float getSplitValue();
	int getAttribute();
	Node * getLeft();
    Node * getRight();
	std::string getLabel();

	//Setters
	void setDepth(int newDepth);
	void setSplitValue(float newValue);
	void setAttribute(int newAttribute);
	void setLeft(Node * newPtr);
    void setRight(Node * newPtr);
	void setLabel(std::string newLabel);
};


#endif
