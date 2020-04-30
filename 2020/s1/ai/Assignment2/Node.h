#ifndef NODE_H
#define NODE_H

#include "data.h"
#include <string>

class Node
{
private:
	int depth;
	float value;
	float point;
	Node * left;
    Node * right;
	std::string label;

public:
	//Constructor
    Node();

	//Getters
	int getDepth();
	float getValue();
	float getPoint();
	Node * getLeft();
    Node * getRight();

	//Setters
	void setDepth(int newDepth);
	void setValue(float newValue);
	void setPoint(float newPoint);
	void setLeft(Node * newPtr);
    void setRight(Node * newPtr);
};


#endif
