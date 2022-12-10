// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include "HashTable.h"

enum Status {empty, occupied, removed};

class HashEntry{
	public:
		HashEntry();
		HashEntry(int key, int value);
		~HashEntry();
		
		//accessor methods
		int getKey();
		void setKey(int key);
		int getValue();
		void setValue(int value);
		Status getStatus();
		void setStatus(Status status);
		
		
	private:
		int key_;
		int value_;
		Status status_;
};

#endif