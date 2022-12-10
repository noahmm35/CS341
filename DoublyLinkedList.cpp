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
	std::cout << std::endl; 
}

void DoublyLinkedList::printHash()
{
	LinkedNode* trav = ll_.getHead();
	std::cout << trav->getEntry().getKey();
	
	while(trav!=nullptr)
	{
		trav=trav->getNextLinkedNode();
		if(trav!=nullptr)
		{
			std::cout << "<-->" << trav->getEntry().getKey();
		}
	}
	std::cout << std::endl; 
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

void DoublyLinkedList::remove(int key)
{
	if(key == ll_.getHead()->getEntry().getKey())
	{
		LinkedNode * currentHead = ll_.getHead();
		if(currentHead->getNextLinkedNode()==nullptr)
		{
			delete currentHead;
			length_=length_-2;
		}
		else
		{
			LinkedNode * nextNode = ll_.getHead()->getNextLinkedNode();
		
			ll_.setHead(nextNode);
			nextNode->setPrevLinkedNode(nullptr);
			currentHead->setNextLinkedNode(nullptr);
		
			delete currentHead;
			length_=length_-1;	
		}
		
	}
	else if(key == ll_.getTail()->getEntry().getKey())
	{
		std::cout << "check 2" << std::endl;
		LinkedNode * currentTail = ll_.getTail();
		LinkedNode * prevNode = ll_.getTail()->getPrevLinkedNode();
		
		ll_.setTail(prevNode);
		prevNode->setNextLinkedNode(nullptr);
		currentTail->setPrevLinkedNode(nullptr);
		
		delete currentTail;
		length_=length_-1;
	}
	else
	{
		std::cout << "check 3" << std::endl;
		LinkedNode * node = ll_.getHead()->getNextLinkedNode();
		bool isFound(0);
		
		while(node!=ll_.getTail())
		{
			if(node->getEntry().getKey() == key)
			{
				isFound=true;
				break;
			}
			node = node->getNextLinkedNode();
		}
		
		if(isFound)
		{
			node->getPrevLinkedNode()->setNextLinkedNode(node->getNextLinkedNode());
			node->getNextLinkedNode()->setPrevLinkedNode(node->getPrevLinkedNode());
			node->setNextLinkedNode(nullptr);
			node->setPrevLinkedNode(nullptr);
			delete node;
			length_=length_-1;
		}
		else
		{
			std::cout << "Key " << key << " not Found!" << std::endl;
		}
	}
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry entry)
{
	if(ll_.getHead()==nullptr)
	{
		LinkedNode * newNode = new LinkedNode(entry,nullptr,nullptr);
		ll_.setTail(newNode);
		ll_.setHead(newNode);
		length_++;
	}
	else
	{	
		LinkedNode * newNode = new LinkedNode(entry,nullptr,ll_.getTail());
		ll_.getTail()->setNextLinkedNode(newNode);
		ll_.setTail(newNode);
	}
	
	length_++;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry entry)
{
	if(!node->hasNextLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(entry, nullptr, node);
		ll_.setTail(newNode);
		node->setNextLinkedNode(newNode);
		
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(entry, node->getNextLinkedNode(), node);
		node->getNextLinkedNode()->setPrevLinkedNode(newNode);
		node->setNextLinkedNode(newNode);
	}
	length_++;
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry entry)
{
	if(!node->hasPrevLinkedNode())
	{
		LinkedNode * newNode = new LinkedNode(entry, node, nullptr);
		ll_.setHead(newNode);
		node->setPrevLinkedNode(newNode);
	}
	else
	{
		LinkedNode * newNode = new LinkedNode(entry, node, node->getPrevLinkedNode());
		node->getPrevLinkedNode()->setNextLinkedNode(newNode);
		node->setPrevLinkedNode(newNode);
	}
	length_++;
}

int DoublyLinkedList::find(int key)
{
	bool isFound(false);
	LinkedNode * trav = ll_.getHead();
	while(!isFound && trav!=nullptr)
	{	
		if(trav->getEntry().getKey() == key)
			isFound=true;
		else
			trav=trav->getNextLinkedNode();
	}
	if(!isFound)
	{
		std::cout << "Key " << key << "was not found!" << std::endl << std::endl;
		return 0;
	}
	else
		return key;
}