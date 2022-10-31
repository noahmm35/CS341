// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList dll;
	
	LinkedNode * test = new LinkedNode(1,nullptr,nullptr);
	LinkedNode * test2 = new LinkedNode(2,nullptr,nullptr);
	LinkedNode * test3 = new LinkedNode(3,nullptr,nullptr);
	
	dll.insertLinkedNode(test,1);
	dll.insertLinkedNode(test2,2);
	dll.insertLinkedNode(test3,3);
	
	dll.printList();
}