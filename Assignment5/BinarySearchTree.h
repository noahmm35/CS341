#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

/**
 * @class BinarySearchTree
 *
 * A Class that simulates a Binary Search Tree.
 */
class BinarySearchTree
{
	public:
		/// Constructor
		BinarySearchTree();
		
		/// Destructor
		~BinarySearchTree();
		
		/**
	     * Returns a pointer to the root node of the BST.
		 *
	     * @return          TreeNode*
	    */ 
		TreeNode * getRoot();
		
		void setRoot(TreeNode * root);
		
		/**
	     * Inserts a data element into the BST.
	     *
		 * @param[in]	   int	data
	    */ 
		virtual void insert(int data);
		
		/**
	     * Helper method to insert a TreeNode into the BST.
	     *
		 * @param[in]	   TreeNode*	root	
		 * @param[in]	   TreeNode*	newNode
		 *
	     * @return          TreeNode*
	    */ 
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		
		void inOrder(TreeNode * root);
		void preOrder(TreeNode * root);
		void postOrder(TreeNode * root);
		
	private:	
		TreeNode * root_; // Pointer to the root node of the BST
};

#endif
