#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
	//Should be null if empty
	Node * head;


public:
	LinkedList();
	LinkedList(int array[], int size);

	void addFront(int newItem);
	void addEnd(int newItem);
	void addAtPosition(int position, int newItem);
	int search(int item);
	void deleteFront();
	void deleteEnd();
	void deletePosition(int position);
	int getItem(int position);
	void printItems();

	~LinkedList();

};

#endif
