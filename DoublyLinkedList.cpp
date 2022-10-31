// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	length_=0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	if(ll_.getHead()!=nullptr)
	{
		delete ll_.getHead();
	}
}

void DoublyLinkedList::printList()
{
	LinkedNode* trav = ll_.getHead();
	std::cout << trav->getData();
	
	while(trav!=nullptr)
	{
		trav=trav->getNextLinkedNode();
		if(trav!=nullptr)
		{
			std::cout << "<-->" << trav->getData();
		}
	}
	std::cout << std::endl; 
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data)
{	
	//node is what you are actively inserting with value of data
	std::cout << "Inserting " << data << "..." << std::endl;
	
	if(ll_.getHead()==nullptr)
	{
		ll_.setTail(node);
		ll_.setHead(node);
	}
	else
	{	
		insertAfterLinkedNode(ll_.getTail(), data);
	}
	length_++;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	if(!node->hasNextLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(data, nullptr, node);
		ll_.setTail(newNode);
		node->setNextLinkedNode(newNode);
		
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(data, node->getNextLinkedNode(), node);
		node->setNextLinkedNode(newNode);
		
		LinkedNode * temp = node->getNextLinkedNode();
		temp->setPrevLinkedNode(newNode);
	}
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	if(!node->hasPrevLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(data, node, nullptr);
		ll_.setHead(newNode);
		node->setPrevLinkedNode(newNode);
		
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(data, node, node->getPrevLinkedNode());
		node->setPrevLinkedNode(newNode);
		
		LinkedNode * temp = node->getPrevLinkedNode();
		temp->setNextLinkedNode(newNode);
	}
}