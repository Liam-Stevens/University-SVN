#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
private:
	int elevation;
	Node * up;
    Node * down;
    Node * left;
    Node * right;
	int posX;
	int posY;
	std::vector<Node *> queuedNodes;
	std::vector<Node *> previousNodes;
	bool path;

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
	int getX();
	int getY();
	Node * getTrace();
	bool getPath();

	//Setters
	void setElevation(int newData);
	void setUp(Node * newPtr);
    void setDown(Node * newPtr);
    void setLeft(Node * newPtr);
    void setRight(Node * newPtr);
	void setPos(int, int);
	void setPath(bool);

	//Traceback
	void insertNode(Node *);
	void printNodes();
	void visited(bool);
	void traceNodes();
};


#endif
