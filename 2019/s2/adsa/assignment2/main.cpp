#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

//The Node Class
class Node
{
private:
	int data;
	int balance;
	Node * nextLower;
	Node * nextHigher;

public:

	//Getters
	int getData()
	{
		return data;
	};

	int getBalance()
	{
		return balance;
	};

	Node * getLowerPtr()
	{
		return nextLower;
	};

	Node * getHigherPtr()
	{
		return nextHigher;
	};


	//Setters
	void setData(int newData)
	{
		data = newData;
	};

	void setBalance(int newBalance)
	{
		balance = newBalance;
	};

	void setPtr(Node * newPtr)
	{
		nextLower = newPtr;
		nextHigher = newPtr;
	};

	void setLowerPtr(Node * newPtr)
	{
		nextLower = newPtr;
	};

	void setHigherPtr(Node * newPtr)
	{
		nextHigher = newPtr;
	};

};


class AVLTree
{
private:
	Node * head;

public:
	//Constructors
	AVLTree()
	{
		head = NULL;
	};

	AVLTree(vector<int> input)
	{
		head = NULL;
		for (int i = 0; i < input.size(); i++)
		{
			insertNode(input[i]);
		}
	};


	//Functions

	//Insert a number into the tree
	void insertNode(int number)
	{
		Node * pick;

		//Insert Node if head is empty
		if (head == NULL)
		{
			pick = new Node();
			pick->setPtr(NULL);
			pick->setData(number);
			head = pick;
			return;
		}

		pick = head;

		while (true)
		{
			//Stop if same number in tree
			if (pick->getData() == number)
			{
				return;
			}
			//Travel to lower number
			else if (pick->getData() > number)
			{
				//Insert Node
				if (pick->getLowerPtr() == NULL)
				{
					Node * tmp;
					tmp = new Node();
					tmp->setPtr(NULL);
					tmp->setData(number);
					pick->setLowerPtr(tmp);
				} else {
					pick = pick->getLowerPtr();
				}
			}
			//Travel to higher number
			else if (pick->getData() < number)
			{
				//Insert Node
				if (pick->getHigherPtr() == NULL)
				{
					Node * tmp;
					tmp = new Node();
					tmp->setPtr(NULL);
					tmp->setData(number);
					pick->setHigherPtr(tmp);
				} else {
					pick = pick->getHigherPtr();
				}
			}
		}

	};

	//Find the node with the contained data
	Node * search(int number)
	{
		Node * pick;
		pick = head;

		while (true)
		{
			//End search
			if (pick == NULL)
			{
				return NULL;
			}

			//Found number
			if (pick->getData() == number)
			{
				return pick;
			}
			//Search lower node
			else if (pick->getData() > number)
			{
				pick = pick->getLowerPtr();
			}
			//Search higher node
			else if (pick->getData() < number)
			{
				pick = pick->getHigherPtr();
			}
		}
	};

	//Find the parent of the node with the contained data
	Node * searchParent(int number)
	{
		Node * pick;
		Node * parent;
		pick = head;
		parent = NULL;

		while (true)
		{
			//End search
			if (pick == NULL)
			{
				return parent;
			}

			//Found parent of number
			if (pick->getData() == number)
			{
				return parent;
			}
			//Search lower node
			else if (pick->getData() > number)
			{
				parent = pick;
				pick = pick->getLowerPtr();
			}
			//Search higher node
			else if (pick->getData() < number)
			{
				parent = pick;
				pick = pick->getHigherPtr();
			}
		}
	};

	//Find the largest child of parent node
	Node * searchLargest(Node * parent)
	{
		Node * pick;
		pick = parent;

		pick = parent->getLowerPtr();

		while(true)
		{
			if (pick->getHigherPtr() != NULL)
			{
				pick = pick->getHigherPtr();
			}
			else
			{
				return pick;
			}
		}

	};

	//Swap two nodes in the tree
	void swapNode(Node * node1, Node * node2)
	{
		int headTest = 0;
		Node * parent1;
		Node * parent2;
		parent1 = searchParent(node1->getData());
		parent2 = searchParent(node2->getData());

		if (parent1 == NULL)
		{
			headTest = 1;
		}
		else if (parent2 == NULL)
		{
			headTest = 2;
		}

		//If the two swaping nodes are connected to eachother
		if (parent1 == node2 || parent2 == node1)
		{
			//If Node2 is the parent of node1
			if (parent1 == node2)
			{
				//If Node2 is the root
				if (headTest == 2)
				{
					head = node1;
					node2->setLowerPtr(node1->getLowerPtr());
					node1->setLowerPtr(node2);
				}
				else
				{
					if (parent2->getLowerPtr() == node2)
					{
						parent2->setLowerPtr(node1);
					}
					else
					{
						parent2->setHigherPtr(node1);
					}
					node2->setLowerPtr(node1->getLowerPtr());
					node1->setLowerPtr(node2);
				}
			}
			//If Node1 is the parent of node2
			else
			{
				//If Node1 is the root
				if (headTest == 1)
				{
					head = node2;
					node1->setLowerPtr(node2->getLowerPtr());
					node2->setLowerPtr(node1);
				}
				else
				{
					if (parent1->getLowerPtr() == node1)
					{
						parent1->setLowerPtr(node2);
					}
					else
					{
						parent1->setHigherPtr(node2);
					}
					node1->setLowerPtr(node2->getLowerPtr());
					node2->setLowerPtr(node1);
				}
			}

			//Swapping remaining Children
			Node * tmpHigher;

			tmpHigher = node1->getHigherPtr();
			node1->setHigherPtr(node2->getHigherPtr());
			node2->setHigherPtr(tmpHigher);
		}
		else
		{
			//If one of the nodes is the root
			if(headTest != 0)
			{
				//If the first node is the root
				if(headTest == 1)
				{
					head = node2;
					if (parent2->getLowerPtr() == node2)
					{
						parent2->setLowerPtr(node1);
					}
					else
					{
						parent2->setHigherPtr(node1);
					}
				}
				//If the second node is the root
				else if (headTest == 2)
				{
					head = node1;
					if (parent1->getLowerPtr() == node1)
					{
						parent1->setLowerPtr(node2);
					}
					else
					{
						parent1->setHigherPtr(node2);
					}
				}

			}
			//Not changing the root node
			else
			{
				//Move the parent pointer
				if (parent1->getLowerPtr() == node1)
				{
					parent1->setLowerPtr(node2);
				}
				else
				{
					parent1->setHigherPtr(node2);
				}

				if (parent2->getLowerPtr() == node2)
				{
					parent2->setLowerPtr(node1);
				}
				else
				{
					parent2->setHigherPtr(node1);
				}

			}

			//Swapping Children
			Node * tmpLower;
			Node * tmpHigher;

			tmpLower = node1->getLowerPtr();
			tmpHigher = node1->getHigherPtr();
			node1->setLowerPtr(node2->getLowerPtr());
			node1->setHigherPtr(node2->getHigherPtr());
			node2->setLowerPtr(tmpLower);
			node2->setHigherPtr(tmpHigher);
		}

	};

	//Remove the number from the tree
	void removeNode(int number, Node * recursive, Node * recursiveParent)
	{
		//Get the number to remove
		Node * target;
		if (recursive == NULL)
		{
			target = search(number);
		}
		else
		{
			target = recursive;
		}

		//Do nothing if not found
		if (target == NULL)
		{
			return;
		}
		//Do Deletion
		else
		{
			Node * parent;
			if (recursiveParent == NULL)
			{
				parent = searchParent(number);
			}
			else
			{
				parent = recursiveParent;
			}

			//Find which side of parent the target is on
			bool lower = false;
			bool header = false;
			if (parent == NULL)
			{
				header = true;
			}
			else if (parent->getLowerPtr() == target)
			{
				lower = true;
			}
			else if (parent->getHigherPtr() == target)
			{
				lower = false;
			}

			//The target node is a leaf
			if (target->getLowerPtr() == NULL && target->getHigherPtr() == NULL)
			{
				//Delete edge
				if (header == true)
				{
					head = NULL;
				}
				else if (lower == true)
				{
					parent->setLowerPtr(NULL);
				}
				else
				{
					parent->setHigherPtr(NULL);
				}

				//Delete leaf
				delete target;
			}
			//Target node has one child
			else if ((target->getLowerPtr() != NULL && target->getHigherPtr() == NULL) || (target->getLowerPtr() == NULL && target->getHigherPtr() != NULL))
			{
				if (header == true)
				{
					if (target->getLowerPtr() != NULL)
					{
						head = target->getLowerPtr();
					}
					else
					{
						head = target->getHigherPtr();
					}
				}
				//Child on lower side
				else if (target->getLowerPtr() != NULL)
				{
					//Move pointer to parent node
					if (lower == true)
					{
						parent->setLowerPtr(target->getLowerPtr());
					}
					else
					{
						parent->setHigherPtr(target->getLowerPtr());
					}
				}
				//Child on higher side
				else if (target->getHigherPtr() != NULL)
				{
					//Move pointer to parent node
					if (lower == true)
					{
						parent->setLowerPtr(target->getHigherPtr());
					}
					else
					{
						parent->setHigherPtr(target->getHigherPtr());
					}
				}

				//Delete target
				delete target;
			}
			//Target node has two children
			else if (target->getLowerPtr() != NULL && target->getHigherPtr() != NULL)
			{
				Node * largest;
				largest = searchLargest(target);
				Node * largestParent;
				largestParent = searchParent(largest->getData());
				swapNode(target,largest);
				removeNode(number, target, largestParent);
			}
		}
	};

	//Repair the AVL Tree
	void repair()
	{

	};

	//Rebalance the tree
	void rebalance()
	{
		//DO REBALANCE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	};

	//Designed to be called from the deconstructor - removes all nodes from tree
	void clearTree(Node * current, Node * previous)
	{
		//Returns if empty list
		if (current == NULL && previous == NULL)
		{
			return;
		}

		if (current->getLowerPtr() != NULL)
		{
			clearTree(current->getLowerPtr(), current);
		}

		if (current->getHigherPtr() != NULL)
		{
			clearTree(current->getHigherPtr(), current);
		}

		//Delete Node
		if (current != head)
		{
			if (previous->getLowerPtr() == current)
			{
				previous->setLowerPtr(NULL);
			} else if (previous->getHigherPtr() == current)
			{
				previous->setHigherPtr(NULL);
			}
		} else {
			head = NULL;
		}
		delete current;

	};

	//Print in preorder form
	void preorder(Node * tmp)
	{
		if (tmp != head)
		{
			cout << ' ';
		}
		cout << tmp->getData();

		if (tmp->getLowerPtr() != NULL)
		{
			preorder(tmp->getLowerPtr());
		}

		if (tmp->getHigherPtr() != NULL)
		{
			preorder(tmp->getHigherPtr());
		}
	};

	//Print in postorder form
	void postorder(Node * tmp)
	{
		if (tmp->getLowerPtr() != NULL)
		{
			postorder(tmp->getLowerPtr());
		}

		if (tmp->getHigherPtr() != NULL)
		{
			postorder(tmp->getHigherPtr());
		}

		cout << tmp->getData();
		if (tmp != head)
		{
			cout << ' ';
		}
	};

	//Print in inorder form
	void inorder(Node * tmp)
	{
		if (tmp->getLowerPtr() != NULL)
		{
			inorder(tmp->getLowerPtr());
		}
		//MAKESHIFT FIX - ENDING SPACE ON THE LINE - SEE IF THIS NEEDS FIXING <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		cout << tmp->getData() << ' ';

		if (tmp->getHigherPtr() != NULL)
		{
			inorder(tmp->getHigherPtr());
		}
	}

	//Call for prints
	void printTree(int type)
	{
		if (head == NULL)
		{
			cout << "EMPTY" << endl;
			return;
		}

		//Pre-Order
		if (type == 0)
		{
			preorder(head);
			cout << endl;
		}

		//Post-Order
		if (type == 1)
		{
			postorder(head);
			cout << endl;
		}

		//In-Order
		if (type == 2)
		{
			inorder(head);
			cout << endl;
		}

	};


	//Deconstructor
	~AVLTree()
	{
		clearTree(head, NULL);
	};

};

int main()
{
	vector<string> operations;
	string printType;
	string line;
	int errorCount = 0;

	//Take the inputs
	do
	{
		cin >> line;

		if (line == "IN" || line == "PRE" || line == "POST")
		{
			printType = line;
			break;
		}
		else
		{
			operations.push_back(line);
		}

		if (errorCount > 102)
		{
			cout << "ERROR 0" << endl;
			return 1;
		}
		errorCount++;

	}
	while(true);

	AVLTree tree1;

	//Loop over the operations from input
	for (int j = 0; j < operations.size(); j++)
	{
		if(operations[j][0] == 'A')
		{
			operations[j].erase(operations[j].begin());
			int tmp = stoi(operations[j]);
			tree1.insertNode(tmp);
		}
		else if (operations[j][0] == 'D')
		{
			operations[j].erase(operations[j].begin());
			int tmp = stoi(operations[j]);
			tree1.removeNode(tmp, NULL, NULL);
		}
		else
		{
			cout << "ERROR 1" << endl;
			return 1;
		}
	}

	//Print Tree
	if (printType == "IN")
	{
		tree1.printTree(0);
	}
	else if (printType == "PRE")
	{
		tree1.printTree(1);
	}
	else if (printType == "POST")
	{
		tree1.printTree(2);
	}
	else
	{
		cout << "ERROR 2" << endl;
		return 1;
	}

	return 0;
}
