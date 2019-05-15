#include "LinkedList.h"
#include "Node.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

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

	/*
	int array[5] = {1,2,3,4,5};

	LinkedList test(array,5);

	test.deleteEnd();

	test.addAtPosition(3, 8);

	test.printItems();

	test.deletePosition(6);

	test.printItems();
	*/


	//Takes inputs
    string line;
	int numInput[100];
	string funcInput[3];
	int size = 0;
	int	funcInc = 0;
	bool end = false;

	do {
		cin >> line;

		if(((int)line[0] - 48) < 10 && end == false)
		{
			numInput[size] = atoi (line.c_str());
		} else {
			end = true;
		}

		if(end == true)
		{
			funcInput[funcInc] = line;
			funcInc++;
		} else {
			size++;
		}
	}
	while(funcInc < 3);

	//Create object
	LinkedList list(numInput,size);

	//Ifs
	if(funcInput[0] == "AF") {
		list.addFront(atoi (funcInput[1].c_str()));
	} else if(funcInput[0] == "AE") {
		list.addEnd(atoi (funcInput[1].c_str()));
	} else if(funcInput[0] == "AP") {
		list.addAtPosition(atoi (funcInput[1].c_str()),atoi (funcInput[2].c_str()));
	} else if(funcInput[0] == "S") {
		list.search(atoi (funcInput[1].c_str()));
	} else if(funcInput[0] == "DF") {
		list.deleteFront();
	} else if(funcInput[0] == "DE") {
		list.deleteEnd();
	} else if(funcInput[0] == "DP") {
		list.deletePosition(atoi (funcInput[1].c_str()));
	} else if(funcInput[0] == "GI") {
		list.getItem(atoi (funcInput[1].c_str()));
	}

	list.printItems();

}
