#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

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
	if( position < 1 || position == 1 )
	{
		addFront(newItem);
	} else {
		Node * pick;
		pick = head;
		Node * newNode = new Node();

		if (position > 2){
			for(int i = 2; i < position; i++)
			{
				if(pick->getPtr() != NULL) {
					pick = pick->getPtr();
				} else {
					break;
				}
			}
		}

		newNode->setData(newItem);
		newNode->setPtr(pick->getPtr());
		pick->setPtr(newNode);

	}
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
	if(head == NULL)
	{
		//Do Nothing
	}
	else
	{
		head = pick->getPtr();
		delete pick;
	}
}

void LinkedList::deleteEnd() {
	Node * pick = head;
	Node * nuller = pick;
	if (pick != NULL) {

		while(pick->getPtr() != NULL)
		{
			nuller = pick;
			pick = pick->getPtr();
		}

		//delete
		nuller->setPtr(NULL);
		delete pick;

	} else {
		//Do Nothing
	}
}

void LinkedList::deletePosition(int position) {
	bool failed = false;
	if (head == NULL) {
		failed = true;
	} else if ( position < 1 )
	{
		failed = true;
	} else {
		Node * pick = head;
		Node * mover = pick;

		if (position > 1){
			for(int i = 1; i < position; i++)
			{
				if(pick->getPtr() != NULL) {
					mover = pick;
					pick = pick->getPtr();
				} else {
					failed = true;
					break;
				}
			}
		}

		if (position == 1 && failed == false)
		{
			deleteFront();
		} else if (failed == false) {
			mover->setPtr(pick->getPtr());
			delete pick;
		}
	}

	if (failed == true)
	{
		cout << "outside range" << endl;
	}

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
			cout << pick->getData() << " ";
			return pick->getData();
		}
	}

	int value = std::numeric_limits<int>::max();

	cout << value << " ";
	return value; //return std :: numeric limits < int >:: max()
	//THIS PART IS NOT COMPLETE
}

void LinkedList::printItems() {

	Node * pick;
	pick = head;
	while(pick != NULL)
	{
		cout << pick->getData() << " ";
		pick = pick->getPtr();
	}
	cout << endl;
}

LinkedList::~LinkedList() {
	while(head != NULL)
	{
		deleteFront();
	}
}
