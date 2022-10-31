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
		
		void insertLinkedNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);
		
	private:
		LinkedList ll_;
		int length_;
};