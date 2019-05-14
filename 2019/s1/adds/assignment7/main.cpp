#include "LinkedList.h"
#include "Node.h"

#include <iostream>

using namespace std;

int main() {
	/*
	Node test;
	Node test2;

	test.setData(65);
	cout << test.getData() << endl;
	
	Node * ptr;
	ptr = &test2;
	ptr->setData(88);
	test.setPtr(ptr);
	Node * ptr2;
	ptr2 = test.getPtr();
	cout << ptr2->getData() << endl;
	*/

	int array[5] = {1,2,3,4,5};

	LinkedList test(array,5);
	test.printItems();

	test.deleteFront();

	test.printItems();

	test.search(3);

}