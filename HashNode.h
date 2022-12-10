#ifndef HASHNODE_H
#define HASHNODE_H

class HashNode
{
	public:		
		/// Constructor
		Node(int data);
		
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
		
	protected:
		// We need to do this to prevent a Node from being
		// created that has no value.
		
		/// Constructor (Default)
		Node() {}
};

#endif