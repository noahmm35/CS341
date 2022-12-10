// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashEntry.h"

class HashTableArray : public HashTable
{
	public:
		HashTableArray();
		HashTableArray(int size);
		~HashTableArray();
		
		//Accessor Methods
		int getSize();
		void setSize(int size);
		void setProbe(bool probe);
		
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
	private:
		HashEntry * entry_;
		int size_;
		bool probe_;
};

#endif