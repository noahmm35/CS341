// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "HashTableChaining.h"

HashTableChaining::HashTableChaining() : HashTableChaining(0)
{
	
}

HashTableChaining::HashTableChaining(int size)
{
	entry_ = new DoublyLinkedList[size];
}

HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

int HashTableChaining::getSize()
{
	return size_;
}

void HashTableChaining::setSize(int size)
{
	size_=size;
}

void HashTableChaining::insert(int key, int value)
{
	HashEntry x(key,value);
	int hash = x.getKey() % size_;
	
	entry_[hash].insertLinkedNode(entry_[hash].getTail(), x);
}

int HashTableChaining::search(int key)
{
	int hash = key % size_;
	
	if(entry_[hash].find(key) == key)
		std::cout << "Key: " << key << " Value: 1" << std::endl << std::endl;
	else
		std::cout << "Key " << key << " was not found!" << std::endl << std::endl;
	return 1;
}

void HashTableChaining::remove(int key)
{
	int hash = key % size_;
	
	if(entry_[hash].find(key) == key)
	{
		entry_[hash].remove(key);
		std::cout << "Key " << key << " removed!" << std::endl << std::endl;
		std::cout << entry_[hash].getLength() << std::endl;
	}
	else
		std::cout << "Key " << key << " was not found!" << std::endl << std::endl;
}

void HashTableChaining::print()
{
	std::cout << "********************" << std::endl;
	
	for(int i=0;i<size_;i++)
	{
		if(entry_[i].getLength()==0)
			std::cout << "[" << i << "]: " << std::endl;
		else
		{
			std::cout << "[" << i << "]: ";
			entry_[i].printHash();
		}
	}
	
	std::cout << "********************" << std::endl << std::endl;
}