#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int elevation;
	Node * up;
    Node * down;
    Node * left;
    Node * right;

public:
	//Constructor
    Node();
    Node(int newData);

	//Getters
	int getElevation();
	Node * getUp();
    Node * getDown();
    Node * getLeft();
    Node * getRight();

	//Setters
	void setElevation(int newData);
	void setUp(Node * newPtr);
    void setDown(Node * newPtr);
    void setLeft(Node * newPtr);
    void setRight(Node * newPtr);
};


#endif
