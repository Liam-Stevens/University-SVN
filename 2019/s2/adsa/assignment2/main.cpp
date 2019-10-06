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
	int depth;
	int height;
	Node * nextLower;
	Node * nextHigher;

public:
	Node()
	{
		balance = 0;
	};

	//Getters
	int getData()
	{
		return data;
	};

	int getBalance()
	{
		return balance;
	};

	int getDepth()
	{
		return depth;
	};

	int getHeight()
	{
		return height;
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

	void setDepth(int newDepth)
	{
		depth = newDepth;
	};

	void setHeight(int newHeight)
	{
		height = newHeight;
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


	//Functions

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
		pick = parent->getLowerPtr();

		while(true)
		{
			//Find furthest right node from left branch
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

	//Set the Balance of parent nodes from the target
	void updateBalance(Node * tmp)
	{
		//End if root or non-existant
		if (tmp == NULL)
		{
			return;
		}

		//Call down in post-order
		if (tmp->getLowerPtr() != NULL)
		{
			updateBalance(tmp->getLowerPtr());
		}
		if (tmp->getHigherPtr() != NULL)
		{
			updateBalance(tmp->getHigherPtr());
		}

		//Update Balance
		int heightLeft;
		int heightRight;

		if(tmp->getLowerPtr() == NULL)
		{
			heightLeft = 0;
		}
		else
		{
			heightLeft = tmp->getLowerPtr()->getHeight();
		}

		if(tmp->getHigherPtr() == NULL)
		{
			heightRight = 0;
		}
		else
		{
			heightRight = tmp->getHigherPtr()->getHeight();
		}

		int bal = heightLeft - heightRight;
		tmp->setBalance(bal);
	};

	void updateDepth(Node * tmp, int depth)
	{
		//End if root or non-existant
		if (tmp == NULL)
		{
			return;
		}

		//Call down in post-order
		if (tmp->getLowerPtr() != NULL)
		{
			updateDepth(tmp->getLowerPtr(), depth+1);
		}
		if (tmp->getHigherPtr() != NULL)
		{
			updateDepth(tmp->getHigherPtr(), depth+1);
		}

		//Set Depth
		tmp->setDepth(depth);

		//Update height
		int heightLeft;
		int heightRight;

		if (tmp->getLowerPtr() == NULL)
		{
			heightLeft = 1;
		}
		else
		{
			heightLeft = tmp->getLowerPtr()->getHeight()+1;
		}

		if(tmp->getHigherPtr() == NULL)
		{
			heightRight = 1;
		}
		else
		{
			heightRight = tmp->getHigherPtr()->getHeight()+1;
		}

		int maxHeight = heightLeft;
		if (maxHeight < heightRight)
		{
			maxHeight = heightRight;
		}

		tmp->setHeight(maxHeight);
	};

	//Left Rotation of nodes
	void leftRotation(Node * target)
	{
		Node * parent;
		parent = searchParent(target->getData());
		//X
		Node * rotation;
		rotation = target->getHigherPtr();
		//B
		Node * change;
		change = rotation->getLowerPtr();

		//Change parent ptr
		if (parent == NULL)
		{
			head = rotation;
		}
		else
		{
			if(parent->getLowerPtr() == target)
			{
				parent->setLowerPtr(rotation);
			}
			else if (parent->getHigherPtr() == target)
			{
				parent->setHigherPtr(rotation);
			}
		}

		//Change child ptr
		rotation->setLowerPtr(target);
		target->setHigherPtr(change);

		//Do Balancing
		updateDepth(head,0);
		updateBalance(head);
	};

	//Right Rotation of nodes
	void rightRotation(Node * target)
	{
		Node * parent;
		parent = searchParent(target->getData());
		//X
		Node * rotation;
		rotation = target->getLowerPtr();
		//B
		Node * change;
		change = rotation->getHigherPtr();

		//Change parent ptr
		if (parent == NULL)
		{
			head = rotation;
		}
		else
		{
			if(parent->getLowerPtr() == target)
			{
				parent->setLowerPtr(rotation);
			}
			else if (parent->getHigherPtr() == target)
			{
				parent->setHigherPtr(rotation);
			}
		}

		//Change child ptr
		rotation->setHigherPtr(target);
		target->setLowerPtr(change);

		//Do Balancing
		updateDepth(head,0);
		updateBalance(head);
	};

	//Right-Left Rotation of nodes in tree
	void rightLeftRotation(Node * target)
	{
		Node * parent;
		parent = searchParent(target->getData());
		//X
		Node * remain;
		remain = target->getHigherPtr();
		//W
		Node * topper;
		topper = remain->getLowerPtr();
		//B
		Node * change1;
		change1 = topper->getLowerPtr();
		//C
		Node * change2;
		change2 = topper->getHigherPtr();

		//Change parent ptr
		if (parent == NULL)
		{
			head = topper;
		}
		else
		{
			if(parent->getLowerPtr() == target)
			{
				parent->setLowerPtr(topper);
			}
			else if (parent->getHigherPtr() == target)
			{
				parent->setHigherPtr(topper);
			}
		}

		//Change child ptrs
		topper->setLowerPtr(target);
		topper->setHigherPtr(remain);
		target->setHigherPtr(change1);
		remain->setLowerPtr(change2);

		//Do Balancing
		updateDepth(head,0);
		updateBalance(head);
	};

	//Left-Right Rotation of nodes
	void leftRightRotation(Node * target)
	{
		Node * parent;
		parent = searchParent(target->getData());
		//X
		Node * remain;
		remain = target->getLowerPtr();
		//W
		Node * topper;
		topper = remain->getHigherPtr();
		//B
		Node * change1;
		change1 = topper->getLowerPtr();
		//C
		Node * change2;
		change2 = topper->getHigherPtr();

		//Change parent ptr
		if (parent == NULL)
		{
			head = topper;
		}
		else
		{
			if(parent->getLowerPtr() == target)
			{
				parent->setLowerPtr(topper);
			}
			else if (parent->getHigherPtr() == target)
			{
				parent->setHigherPtr(topper);
			}
		}

		//Change child ptrs
		topper->setHigherPtr(target);
		topper->setLowerPtr(remain);
		target->setLowerPtr(change2);
		remain->setHigherPtr(change1);

		//Do Balancing
		updateDepth(head,0);
		updateBalance(head);
	};

	void insertionBalanceCheck(Node * recentNode)
	{
		string direction1 = "null";
		string direction2 = "null";
		Node * pick;
		pick = recentNode;
		Node * trail;
		trail = recentNode;

		//End if at root
		if(pick == NULL)
		{
			return;
		}

		while(true)
		{
			//Check if a unbalanced Node
			if (pick->getBalance() == -2 || pick->getBalance() == 2)
			{
				//Check conditions for rotation
				if (pick->getBalance() == -2 && direction2 == "right")
				{
					leftRotation(pick);
				}
				else if (pick->getBalance() == 2 && direction2 == "left")
				{
					rightRotation(pick);
				}
				else if (pick->getBalance() == -2 && direction2 == "left")
				{
					rightLeftRotation(pick);
				}
				else if (pick->getBalance() == 2 && direction2 == "right")
				{
					leftRightRotation(pick);
				}
				break;
			}
			//Climb the tree by a node
			else
			{
				trail = pick;
				pick = searchParent(pick->getData());

				//End if at root
				if(pick == NULL)
				{
					return;
				}

				//Track which side the node was inserted into
				if (pick->getLowerPtr() == trail)
				{
					direction2 = direction1;
					direction1 = "left";
				}
				else if (pick->getHigherPtr() == trail)
				{
					direction2 = direction1;
					direction1 = "right";
				}
			}

		}

	};

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
			updateDepth(head, 0);
			updateBalance(head);
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
					break;
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
					break;
				} else {
					pick = pick->getHigherPtr();
				}
			}
		}

		//Do Balance
		updateDepth(head, 0);
		updateBalance(head);
		insertionBalanceCheck(search(number));
	};

	//Swap two nodes in the tree
	void swapNode(Node * node1, Node * node2)
	{
		int headTest = 0;
		Node * parent1;
		Node * parent2;
		parent1 = searchParent(node1->getData());
		parent2 = searchParent(node2->getData());

		//Test to see if one of the parents is the root
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

			//Update Height, Depth and Balance
			updateDepth(head,0);
			updateBalance(head);
		}

	};

	//Check the balance and repair the tree
	void removeBalanceCheck(Node * initial)
	{
		Node * pick;
		pick = initial;
		Node * trail;
		trail = initial;
		string direction = "null";

		//End if at root
		if(pick == NULL)
		{
			return;
		}

		while(true)
		{
			//Check if a unbalanced Node
			if (pick->getBalance() == -2 || pick->getBalance() == 2)
			{
				//Check conditions for rotation
				if (pick->getBalance() == -2)
				{
					int heightOfD;
					int heightOfW;

					//Get the height of the left sub-branch
					if(pick->getHigherPtr()->getHigherPtr() != NULL)
					{
						heightOfD = pick->getHigherPtr()->getHigherPtr()->getHeight();
					}
					else
					{
						heightOfD = 0;
					}

					//Get the height of the right sub-branch
					if(pick->getHigherPtr()->getLowerPtr() != NULL)
					{
						heightOfW = pick->getHigherPtr()->getLowerPtr()->getHeight();
					}
					else
					{
						heightOfW = 0;
					}

					//Determine which rotation
					if (heightOfD >= heightOfW)
					{
						leftRotation(pick);
					}
					else if (heightOfD < heightOfW)
					{
						rightLeftRotation(pick);
					}
					else
					{
						cout << "ERROR 31" << endl;
					}
				}
				else if (pick->getBalance() == 2)
				{
					int heightOfA;
					int heightOfW;

					//Get the height of the left sub-branch
					if(pick->getLowerPtr()->getLowerPtr() != NULL)
					{
						heightOfA = pick->getLowerPtr()->getLowerPtr()->getHeight();
					}
					else
					{
						heightOfA = 0;
					}

					//Get the height of the right sub-branch
					if(pick->getLowerPtr()->getHigherPtr() != NULL)
					{
						heightOfW = pick->getLowerPtr()->getHigherPtr()->getHeight();
					}
					else
					{
						heightOfW = 0;
					}

					//Determine which rotation
					if (heightOfA >= heightOfW)
					{
						rightRotation(pick);
					}
					else if (heightOfA < heightOfW)
					{
						leftRightRotation(pick);
					}
					else
					{
						cout << "ERROR 32" << endl;
					}
				}

			}


			//Climb the tree by a node
			trail = pick;
			pick = searchParent(pick->getData());

			//End if at root
			if(pick == NULL)
			{
				return;
			}

			//Track which side the node was deleted from
			if (pick->getLowerPtr() == trail)
			{
				direction = "left";
			}
			else if (pick->getHigherPtr() == trail)
			{
				direction = "right";
			}
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
			//Get parent if one is not pre-specified
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
			bool lower;
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
			else
			{
				cout << "ERROR 55" << endl;
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
				else if (lower == false)
				{
					parent->setHigherPtr(NULL);
				}

				//Delete leaf and update balance
				delete target;
				updateDepth(head,0);
				updateBalance(head);
				removeBalanceCheck(parent);
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

				//Delete target and update balance
				delete target;
				updateDepth(head,0);
				updateBalance(head);
				removeBalanceCheck(parent);
			}
			//Target node has two children
			else if (target->getLowerPtr() != NULL && target->getHigherPtr() != NULL)
			{
				Node * largest;
				largest = searchLargest(target);
				Node * largestParent;
				largestParent = searchParent(largest->getData());

				swapNode(target,largest);

				//In case the nodes are next to eachother
				if (largestParent == target)
				{
					largestParent = largest;
				}
				removeNode(number, target, largestParent);

				//Do Balancing
				updateDepth(head,0);
				updateBalance(head);
				removeBalanceCheck(parent);
			}
		}
	};

	//Designed to be called from the deconstructor - removes all nodes from tree
	void clearTree(Node * current, Node * previous)
	{
		//Returns if empty list
		if (current == NULL && previous == NULL)
		{
			return;
		}

		//Moves through tree in post-order
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
		cout << tmp->getData() << ' ';

		if (tmp->getHigherPtr() != NULL)
		{
			inorder(tmp->getHigherPtr());
		}
	}

	//Preorder print Depth (For Debugging)
	void printDepth(Node * tmp)
	{
		if (tmp->getLowerPtr() != NULL)
		{
			printDepth(tmp->getLowerPtr());
		}

		if (tmp->getHigherPtr() != NULL)
		{
			printDepth(tmp->getHigherPtr());
		}

		cout << tmp->getDepth();
		if (tmp != head)
		{
			cout << ' ';
		}
	};

	//Preorder Print Balance (For Debugging)
	void printBalance(Node * tmp)
	{
		if (tmp->getLowerPtr() != NULL)
		{
			printBalance(tmp->getLowerPtr());
		}

		if (tmp->getHigherPtr() != NULL)
		{
			printBalance(tmp->getHigherPtr());
		}

		cout << tmp->getBalance();
		if (tmp != head)
		{
			cout << ' ';
		}
	};

	//Preorder Print Height (For Debugging)
	void printHeight(Node * tmp)
	{
		if (tmp->getLowerPtr() != NULL)
		{
			printHeight(tmp->getLowerPtr());
		}

		if (tmp->getHigherPtr() != NULL)
		{
			printHeight(tmp->getHigherPtr());
		}

		cout << tmp->getHeight();
		if (tmp != head)
		{
			cout << ' ';
		}
	};

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

		//Debug Depth
		if (type == 3)
		{
			printDepth(head);
			cout << " (Depth)" << endl;
		}

		//Debug Balance
		if (type == 4)
		{
			printBalance(head);
			cout << " (Balance)" << endl;
		}

		//Debug Height
		if (type == 5)
		{
			printHeight(head);
			cout << " (Height)" << endl;
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

		//Check for end of line
		if (line == "IN" || line == "PRE" || line == "POST")
		{
			printType = line;
			break;
		}
		//Push back operation
		else
		{
			operations.push_back(line);
		}

		//End loop if too large
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
	for (int j = 0; (unsigned)j < operations.size(); j++)
	{
		//Add to tree
		if(operations[j][0] == 'A')
		{
			operations[j].erase(operations[j].begin());
			int tmp = stoi(operations[j]);
			tree1.insertNode(tmp);
		}
		//Remove from tree
		else if (operations[j][0] == 'D')
		{
			operations[j].erase(operations[j].begin());
			int tmp = stoi(operations[j]);
			tree1.removeNode(tmp, NULL, NULL);
		}
		else
		{
			cout << "ERROR 20" << endl;
			return 1;
		}
	}

	//Print Tree
	if (printType == "PRE")
	{
		tree1.printTree(0);
	}
	else if (printType == "POST")
	{
		tree1.printTree(1);
	}
	else if (printType == "IN")
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
