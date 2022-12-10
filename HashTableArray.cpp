// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "HashTableArray.h"

HashTableArray::HashTableArray() : HashTableArray(0)
{
	
}

HashTableArray::HashTableArray(int size)
{
	entry_= new HashEntry[size];
}

HashTableArray::~HashTableArray()
{
	delete [] entry_;
}

int HashTableArray::getSize()
{
	return size_;
}

void HashTableArray::setSize(int size)
{
	size_=size;
}

void HashTableArray::insert(int key, int value)
{
	HashEntry x(key,value);
	int hash = x.getKey()%size_;
	
	if(entry_[hash].getStatus() == 0 || entry_[hash].getStatus() == 2)
	{
		entry_[hash] = x;
		entry_[hash].setStatus(occupied);
	}
	else
	{
		int n(1);
		while(entry_[hash].getStatus()==1)
		{
			if(probe_) //if probe is true, linear probing
			{
				if(hash==size_-1)
				{
					hash=0;
				}
				else
				{
					hash++;
				}
			}
			else //if probe is false, quadratic probing
			{
				if(entry_[hash].getStatus()==1)
				{
					hash=hash+(n*n);
					if(hash==size_)
						hash=0;
					else if(hash>size_)
					{
						hash=(key%size_) + ((n*n)%size_);
						if(hash>size_)
							hash=hash-size_+1;
					}
					n++;
				}
			}
		}
		entry_[hash] = x;
		entry_[hash].setStatus(occupied);
	}
}

int HashTableArray::search(int key)
{
	int hash = key%size_;
	
	if(entry_[hash].getStatus()==0)
	{
		std::cout << "key " << key << " does not exist in the table!" << std::endl;
	}
	else
	{
		int check(0);
		while(entry_[hash].getKey()!=key && check<=size_)
		{
			if(hash==size_-1)
				hash=0;
			else
				hash++;
			check++;
		}
		
		if(check<=size_ && entry_[hash].getStatus()==1)
		{
			std::cout << "Key: " << entry_[hash].getKey() << " Value: " << entry_[hash].getValue() << std::endl << std::endl;
		}
		else
		{
			std::cout << "Key " << key << " is not in the table!" << std::endl << std::endl;
		}
	}
}

void HashTableArray::remove(int key)
{
	int hash = key%size_;
	
	if(entry_[hash].getStatus()==0)
	{
		std::cout << "key " << key << " does not exist in the table!" << std::endl;
	}
	else
	{
		int check(0);
		while(entry_[hash].getKey()!=key && check<=size_)
		{
				if(hash==size_-1)
					hash=0;
				else
					hash++;
			check++;
		}
		
		if(entry_[hash].getKey()==key)
		{
			std::cout << "Key " << key << " removed!" << std::endl << std::endl;
			entry_[hash].setKey(0);
			entry_[hash].setStatus(removed);
		}
		else
			std::cout << "Key " << key << " was not found in the table!" << std::endl << std::endl;
	}
}

void HashTableArray::print()
{
	std::cout << "********************" << std::endl;
	for(int i=0;i<size_;i++)
	{
		if(entry_[i].getStatus()==1)
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		else
			std::cout << "[" << i << "]:" << std::endl;
	}
	std::cout << "********************" << std::endl << std::endl;
}

void HashTableArray::setProbe(bool probe)
{
	probe_=probe;
}