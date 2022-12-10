// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "LinkedList.h"

LinkedList::LinkedList()
{
	head_=nullptr;
	tail_=nullptr;
	length=0;
}

LinkedList::~LinkedList()
{
	if(head_!=nullptr)
		delete head_;
}

bool LinkedList::isEmpty()
{
	return length<=0;
}

int LinkedList::getLength()
{
	return length;
}

void LinkedList::insert(int element)
{
	std::cout << "inserting " << element << "..." << std::endl;
	LinkedNode* ln = new LinkedNode(element, nullptr,nullptr);
	
	if(head_==nullptr)
	{
		head_=ln;
		tail_=ln;
		length++;
	}
	else
	{
		tail_->setNextLinkedNode(ln);
		tail_=ln;
		length++;
	}
}

void LinkedList::insert(HashEntry entry)
{
	LinkedNode * ln = new LinkedNode(entry, nullptr, nullptr);
	
	if(head_==nullptr)
	{
		head_=ln;
		tail_=ln;
		length++;
	}
	else
	{
		tail_->setNextLinkedNode(ln);
		tail_=ln;
		length++;
	}
}

void LinkedList::printList()
{
	LinkedNode* trav = head_;
	std::cout << trav->getData();
	
	 while(trav!=nullptr)
	{
		trav=trav->getNextLinkedNode();
		if(trav!=nullptr)
		{
			std::cout << "-->" << trav->getData();
		}
	} 
	std::cout << std::endl;
}

LinkedNode * LinkedList::getHead()
{
	return head_;
}

void LinkedList::setHead(LinkedNode * head)
{
	head_=head;
}

LinkedNode * LinkedList::getTail()
{
	return tail_;
}

void LinkedList::setTail(LinkedNode * tail)
{
	tail_=tail;
}