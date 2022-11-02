// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"
#include <iostream>

class LinkedList
{
	public:
		//constructor
		LinkedList();
		
		//destructor
		~LinkedList();
		
		//other functions
		bool isEmpty();
		int getLength();
		void insert(int element);
		virtual void printList();
		
		//getters and setters
		virtual LinkedNode * getHead();
		void setHead(LinkedNode * head);
		virtual LinkedNode * getTail();
		void setTail(LinkedNode * tail);
		
	private:
		LinkedNode * head_;
		LinkedNode * tail_;
		int length;
};

#endif