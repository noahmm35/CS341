// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef NODE_H
#define NODE_H

#include "HashEntry.h"

class Node
{
	public:		
		/// Constructor
		Node(int data);
		Node(HashEntry entry);
		
		/// Destructor
		virtual ~Node();
		
		/// Getters/Setters - Accessor Methods
		
		/**
		 * Gets the Nodes Integer value.
		 *
		 * @return		Integer
		 */
		virtual int getValue();
				
		/**
		 * Sets the value of the Node
		 *
		 * @param[in]          Integer		data
		 */
		void setValue(int data);
		
	private:		
		/// Private Attributes
		
		/// Stores the Integer data value
		int data_;
		HashEntry entry_;
		
	protected:
		// We need to do this to prevent a Node from being
		// created that has no value.
		
		/// Constructor (Default)
		Node() {}
};

#endif
