#include "LinkedList.h"
#include <iostream>
using namespace std;

//default constructor
LinkedList::LinkedList() {
	head = nullptr;
}

//the constructor that takes an array of positive size
LinkedList::LinkedList(int* arr, int length) {
    if (length==0)
    {
        head= nullptr;
        return;
    }
    Node * newNode= new Node(arr[0], nullptr);
    head= newNode;
    for(int i=1; i<length; i++)
    {
        Node * nextNewNode= new Node(arr[i], nullptr);
        newNode->next= nextNewNode;
        newNode=nextNewNode;
    }
    return;
}

//the print function
void LinkedList::printItems() {
    if(head != nullptr)
    {
        Node* nextNode = head;
        while (nextNode != nullptr)
        {
            std::cout << nextNode->data << ' ';
            nextNode = nextNode->next;
        }
        std::cout << std::endl;
    }
    return;
}

//The swap function: Assumes that if one of the nodes that are going to be swapped is the first node of the list, then the corresponding nodeBefore is a nullptr.
void LinkedList::swap(Node * nodeBefore1, Node * nodeBefore2){
    if(nodeBefore1==nodeBefore2)
        return;
    if(nodeBefore2==nullptr)
    {
        nodeBefore2= nodeBefore1;
        nodeBefore1=nullptr;
    }
    // at this point we know that the two nodeBefores are not equal, and if one of them is nullptr, it is the first one.
    Node * temp1;
    Node * temp2= nodeBefore2->next;
    if(nodeBefore1==nullptr)
    {
        temp1=head;
        head=temp2;
    }
    else
    {
        temp1= nodeBefore1->next;
        nodeBefore1->next= temp2;
    }
    nodeBefore2->next= temp1;
    Node * temp3= temp2 -> next;
    temp2-> next= temp1-> next;
    temp1-> next= temp3;
}

//bubble sort
void LinkedList::bubbleSort(){
    Node* currentNode = head;
    Node* trackerNode = head;
    if(head== nullptr || currentNode->next == nullptr)
        return;
    Node* nextNode = currentNode->next;
    bool whileFlag= true, change = true;
    while (change)
    {
        whileFlag = true;
        change = false;
        currentNode = head;
        nextNode = currentNode->next;
        while(whileFlag) {
            if(nextNode != nullptr && currentNode != nullptr && trackerNode != nullptr) {
                if(currentNode->data > nextNode->data)
                {
                    swap(currentNode, nextNode);
                    //std::cout << "swapping " << currentNode->data << " and " << nextNode->data << endl;
                    change = true;
                }
            }
            else {
                whileFlag = false;
                break;
            }
            //cout << "next Node" << endl;
            if(trackerNode->next != nullptr)
            {
                currentNode = trackerNode->next->next;
            } else {
                currentNode = nullptr;
                nextNode = nullptr;
            }
            if(currentNode != nullptr)
            {
                nextNode = currentNode->next;
            }
            trackerNode = trackerNode->next;
        }

    }
}



