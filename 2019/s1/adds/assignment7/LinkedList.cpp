#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

using namespace std;

LinkedList::LinkedList() {
	//Points the head to null
	head = NULL;
}

LinkedList::LinkedList(int array[], int size) {
	//Adds the array to the linked list
	head = NULL;
	for(int i = 0; i < size; i++)
	{
		addEnd(array[i]);
	}
}

void LinkedList::addFront(int newItem) {
	//Appends head to the new node and points it to the old head
	Node * pick;
	pick = new Node();
	pick->setPtr(head);
	pick->setData(newItem);
	head = pick;
}

void LinkedList::addEnd(int newItem) {
	Node * pick;
	pick = head;
	//Check for if the array is empty
	if (pick != NULL) {

		//Moves the temp ptr to the end of the list
		while(pick->getPtr() != NULL)
		{
			pick = pick->getPtr();
		}

		//Creates a new node, points it to null and points the old end to it
		Node * newNode = new Node();
		newNode->setPtr(NULL);
		newNode->setData(newItem);
		pick->setPtr(newNode);
	} else {
		//Create the node and connects head
		Node * newNode = new Node();
		newNode->setPtr(NULL);
		newNode->setData(newItem);
		head = newNode;
	}
}

void LinkedList::addAtPosition(int position, int newItem) {
	//Checks if it needs to be added to the start
	if( position < 1 || position == 1 )
	{
		addFront(newItem);
	} else {
		Node * pick;
		pick = head;
		Node * newNode = new Node();

		//Moves temp ptr to 1 position before insertion point
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

		//Connects new node
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

	//Checks for empty list
	if(pick != NULL)
	{
		//Interates over every item in list
		while(pick->getPtr() != NULL && found == false)
		{
			//Checks for item
			if (pick->getData() == item)
			{
				found = true;
			} else
			{
				pick = pick->getPtr();
				pos++;
			}
		}

		//Outputs if it found the item
		if (found == true) {
			cout << pos << " ";
			return pos;
		}

	}

	//Fail condition
	cout << "0 ";
	return 0;
}

void LinkedList::deleteFront() {
	Node * pick;
	pick = head;

	//Checks for empty list
	if(head == NULL)
	{
		//Do Nothing
	}
	else
	{
		//Moves head to next node and deletes old head
		head = pick->getPtr();
		delete pick;
	}
}

void LinkedList::deleteEnd() {
	Node * pick = head;
	Node * nuller = pick;

	//Checks for empty list
	if (pick != NULL) {

		//Iterates to end of list
		while(pick->getPtr() != NULL)
		{
			nuller = pick;
			pick = pick->getPtr();
		}

		//Delete end item
		nuller->setPtr(NULL);
		delete pick;

	} else {
		//Do Nothing
	}
}

void LinkedList::deletePosition(int position) {
	bool failed = false;
	//Check for empty list or invalid input
	if (head == NULL) {
		failed = true;
	} else if ( position < 1 )
	{
		failed = true;
	} else {
		Node * pick = head;
		Node * mover = pick;

		//If not the first element
		if (position > 1){
			//Moves temp ptr to given position
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

		//Check for first element
		if (position == 1 && failed == false)
		{
			deleteFront();
		} else if (failed == false) {
			//Moves ptrs and delete
			mover->setPtr(pick->getPtr());
			delete pick;
		}
	}

	//Fail Condition
	if (failed == true)
	{
		cout << "outside range" << endl;
	}

}

int LinkedList::getItem(int position) {

	bool outside = false;
	Node * pick;
	pick = head;

	//Check for empty list
	if(pick != NULL){
		//Move temp ptr to given position
		for(int i = 0; i < position-1; i++)
		{
			if (pick != NULL)
			{
				pick = pick->getPtr();
			}
			else
			{
				//If the position is outside list size
				outside = true;
				break;
			}
		}

		//Output for success
		if (outside == false)
		{
			cout << pick->getData() << " ";
			return pick->getData();
		}
	}

	//Fail Condition
	int value = std::numeric_limits<int>::max();
	cout << value << " ";
	return value;
}

void LinkedList::printItems() {

	Node * pick;
	pick = head;

	//Iterates over all elements of list
	while(pick != NULL)
	{
		//Output every element
		cout << pick->getData() << " ";
		pick = pick->getPtr();
	}
	cout << endl;
}

LinkedList::~LinkedList() {
	//Calls delete front until empty
	while(head != NULL)
	{
		deleteFront();
	}
}
