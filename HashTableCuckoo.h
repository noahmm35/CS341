// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashEntry.h"

class HashTableCuckoo : public HashTable
{
	public:
		HashTableCuckoo();
		HashTableCuckoo(int size);
		~HashTableCuckoo();
		
		int getSize();
		void setSize(int size);
		
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
		int hash1(int key);
		int hash2(int key);
		
	private:
		HashEntry * entry_;
		HashEntry * entry2_;
		int size_;
};

#endif