// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashEntry.h"
#include "DoublyLinkedList.h"

class HashTableChaining : public HashTable
{
	public:
		HashTableChaining();
		HashTableChaining(int size);
		~HashTableChaining();
		
		int getSize();
		void setSize(int size);
		
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
	private:
		DoublyLinkedList * entry_;
		int size_;
};

#endif