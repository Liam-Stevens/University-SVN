#ifndef NODE_H
#define NODE_H


class Node
{
private:
	int data;
	Node * next;

public:
	//Constructor
	Node();

	//Getters
	int getData();
	Node * getPtr();

	//Setters
	void setData(int newData);
	void setPtr(Node * newPtr);
};

#endif
