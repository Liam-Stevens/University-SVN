#ifndef NODE_H
#define NODE_H


class Node
{
private:
	int data;
	Node * next;

public:
	Node();

	int getData();
	Node * getPtr();

	void setData(int newData);
	void setPtr(Node * newPtr);

};

#endif
