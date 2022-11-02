// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode();
		
		//nondefault constructor
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode); 
		
		//destructor
		~LinkedNode();
		
		//getters and setters
		LinkedNode * getNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		void setNextLinkedNode(LinkedNode * nextLinkedNode); 
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		
		//bool
		bool hasNextLinkedNode();
		bool hasPrevLinkedNode();
		
		int getData();
		
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
		int data_;

};

#endif