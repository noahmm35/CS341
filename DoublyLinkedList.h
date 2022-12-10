// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include "LinkedList.h"



class DoublyLinkedList: public LinkedList 
{
	public:
		
		DoublyLinkedList();
		~DoublyLinkedList();
		
		virtual void printList();
		void printHash();
		
		void insertLinkedNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);
		void insertLinkedNode(LinkedNode * node, HashEntry entry);
		void insertAfterLinkedNode(LinkedNode * node, HashEntry entry);
		void insertBeforeLinkedNode(LinkedNode * node, HashEntry entry);
		int find(int key);
		int getLength();
		int countHeadHops(int data);
		int countTailHops(int data);
		
		virtual LinkedNode * getHead();
		virtual LinkedNode * getTail();
		
		void remove(int key);
		
	private:
		LinkedList ll_;
		int length_;
};