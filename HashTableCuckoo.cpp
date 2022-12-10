// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo() : HashTableCuckoo(0)
{
	
}

HashTableCuckoo::HashTableCuckoo(int size)
{
	entry_ = new HashEntry[size];
	entry2_ = new HashEntry[size];
}

HashTableCuckoo::~HashTableCuckoo()
{
	delete [] entry2_;
	delete [] entry_;
}

int HashTableCuckoo::getSize()
{
	return size_;
}

void HashTableCuckoo::setSize(int size)
{
	size_=size;
}

void HashTableCuckoo::insert(int key, int value)
{
	//if entry2 gets booted, send it back to entry1, if they ping pong > size of hashtable, cycle
	
	int h = hash1(key);
	HashEntry x(key,value);
	
	if(entry_[h].getStatus()==0 || entry_[h].getStatus()==2)
	{
		entry_[h] = x;
		entry_[h].setStatus(occupied);
	}
	else
	{
		HashEntry y = entry_[h];
		int h2= hash2(y.getKey());
		entry_[h] = x;
		entry_[h].setStatus(occupied);
		
		if(entry2_[h2].getStatus()==0 || entry2_[h2].getStatus()==2)
		{
			entry2_[h2] = y;
			entry2_[h2].setStatus(occupied);
		}
		else
		{	
			HashEntry z = entry2_[h2];
			entry2_[h2] = y;
			entry2_[h2].setStatus(occupied);
			
			int h3 = hash1(z.getKey());
			entry_[h3] = z;
			entry_[h3].setStatus(occupied);
		}
	}
}

int HashTableCuckoo::search(int key)
{
	int h = hash1(key);
	int h2 = hash2(key);
	
	if(entry_[h].getKey() == key)
		std::cout << "Key: " << key << " Value: " <<  entry_[h].getValue() << std::endl << std::endl;
	else if (entry2_[h2].getKey() == key)
		std::cout << "Key: " << key << " Value: " <<  entry2_[h2].getValue() << std::endl << std::endl;
	else
		std::cout << "Key " << key << " does not exist in the table!" << std::endl << std::endl;
}

void HashTableCuckoo::remove(int key)
{
	int h = hash1(key);
	int h2 = hash2(key);
	
	if(entry_[h].getKey() == key)
	{
		std::cout << "Key " << key << " removed!" << std::endl << std::endl;
		entry_[h].setKey(0);
		entry_[h].setStatus(removed);
	}
	else if (entry2_[h2].getKey() == key)
	{
		std::cout << "Key " << key << " removed!" << std::endl << std::endl;
		entry2_[h2].setKey(0);
		entry2_[h2].setStatus(removed);
	}
	else
		std::cout << "Key " << key << " does not exist in the table!" << std::endl << std::endl;
}

void HashTableCuckoo::print()
{
	std::cout << "********************" << std::endl;
	for(int i=0;i<size_;i++)
	{
		if(entry_[i].getStatus()==1)
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		else
			std::cout << "[" << i << "]:" << std::endl;
	}
	std::cout << "********************" << std::endl;
	std::cout << "********************" << std::endl;
	for(int i=0;i<size_;i++)
	{
		if(entry2_[i].getStatus()==1)
			std::cout << "[" << i << "]: " << entry2_[i].getKey() << std::endl;
		else
			std::cout << "[" << i << "]:" << std::endl;
	}
	std::cout << "********************" << std::endl << std::endl;
}

int HashTableCuckoo::hash1(int key)
{
	return key%size_;
}

int HashTableCuckoo::hash2(int key)
{
	return (key/size_)%size_;
}