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
	std::cout << std::endl << std::endl; 
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data)
{	
	//node is what you are actively inserting with value of data
	//std::cout << "Inserting " << data << "..." << std::endl;

	if(ll_.getHead()==nullptr)
	{
		LinkedNode * newNode = new LinkedNode(data,nullptr,nullptr);
		ll_.setTail(newNode);
		ll_.setHead(newNode);
		length_++;
	}
	else
	{	
		LinkedNode * newNode = new LinkedNode(data,nullptr,ll_.getTail());
		ll_.getTail()->setNextLinkedNode(newNode);
		ll_.setTail(newNode);
	}
	
	length_++;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	//std::cout << "Inserting " << data << "..." << std::endl;
	
	if(!node->hasNextLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(data, nullptr, node);
		ll_.setTail(newNode);
		node->setNextLinkedNode(newNode);
		
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(data, node->getNextLinkedNode(), node);
		node->getNextLinkedNode()->setPrevLinkedNode(newNode);
		node->setNextLinkedNode(newNode);
	}
	length_++;
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	//std::cout << "Inserting " << data << "..." << std::endl;
	
	if(!node->hasPrevLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(data, node, nullptr);
		ll_.setHead(newNode);
		node->setPrevLinkedNode(newNode);
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(data, node, node->getPrevLinkedNode());
		node->getPrevLinkedNode()->setNextLinkedNode(newNode);
		node->setPrevLinkedNode(newNode);
	}
	length_++;
}

int DoublyLinkedList::getLength()
{
	return length_;
}

int DoublyLinkedList::countHeadHops(int data)
{
	int hop(0);
	LinkedNode * check = ll_.getHead();
	
	if(data<check->getData()) //this means that data is going to be the new head to minimize hops
		return 0;
	else if(data>ll_.getTail()->getData())
		return length_+1;
	else
	{	
		while(!(check->getNextLinkedNode()->getData()>data && check->getData()<=data) && hop<length_)
		{
			check=check->getNextLinkedNode();
			hop++;
		}
		
		return hop+1;
	}
}

int DoublyLinkedList::countTailHops(int data)
{	
	int hop(0); 
	LinkedNode * check = ll_.getTail();
	
	if(data>check->getData()) //this means that data is going to be the new tail in order to minimize hops
		return 0;
	else if(data<ll_.getHead()->getData())
		return length_+1;
	else
	{	
		while(!(check->getData()>data && check->getPrevLinkedNode()->getData()<=data) && hop<length_-1)
		{
			check=check->getPrevLinkedNode();
			hop++;
		}
		
		return hop+1;
	}
}

LinkedNode * DoublyLinkedList::getTail()
{
	return ll_.getTail();
}

LinkedNode * DoublyLinkedList::getHead()
{
	return ll_.getHead();
}
