#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::LinkedList(int array[], int size) {
	head = NULL;
	for(int i = 0; i < size; i++)
	{
		addEnd(array[i]);
	}
}

void LinkedList::addFront(int newItem) {
	Node * pick;
	pick = new Node();
	pick->setPtr(head);
	pick->setData(newItem);
	head = pick;
}

void LinkedList::addEnd(int newItem) {
	Node * pick;
	pick = head;
	if (pick != NULL) {

		while(pick->getPtr() != NULL)
		{
			pick = pick->getPtr();
		}

		Node * newNode = new Node();
		newNode->setPtr(NULL);
		newNode->setData(newItem);
		pick->setPtr(newNode);
	} else {
		Node * newNode = new Node();
		newNode->setPtr(NULL);
		newNode->setData(newItem);
		head = newNode;
	}
}

void LinkedList::addAtPosition(int position, int newItem) {

}

int LinkedList::search(int item) {

	bool found = false;
	int pos = 1;
	Node * pick;
	pick = head;
	if(pick != NULL)
	{

		while(pick->getPtr() != NULL && found == false)
		{
			if (pick->getData() == item)
			{
				found = true;
			} else
			{
				pick = pick->getPtr();
				pos++;
			}
		}
		if (found == true) {
			cout << pos << " ";
			return pos;
		}

	}

	cout << "0 ";
	return 0;
}

void LinkedList::deleteFront() {
	Node * pick;
	pick = head;
	head = pick->getPtr();
	delete pick;
}

void LinkedList::deleteEnd() {

}

void LinkedList::deletePosition(int position) {

}

int LinkedList::getItem(int position) {

	bool outside = false;
	Node * pick;
	pick = head;
	if(pick != NULL){
		for(int i = 0; i < position-1; i++)
		{
			if (pick != NULL)
			{
				pick = pick->getPtr();
			}
			else
			{
				outside = true;
				break;
			}
		}
		if (outside == false)
		{
			cout << pick->getData() << endl;
			return pick->getData();
		}
	} else
	{
		//IF LIST IS EMPTY
	}

	cout << "std :: numeric limits < int >:: max()" << " ";
	return 0; //return std :: numeric limits < int >:: max()
	//THIS PART IS NOT COMPLETE
}

void LinkedList::printItems() {

	Node * pick;
	pick = head;
	while(pick != NULL)
	{
		cout << pick->getData() << endl;
		pick = pick->getPtr();
	}
}

LinkedList::~LinkedList() {

}