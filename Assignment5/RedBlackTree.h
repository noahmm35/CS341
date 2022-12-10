// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree
{
	public:
		RedBlackTree();
		virtual ~RedBlackTree() {}
		
		virtual void insert(int data);
		void printRedNodes(TreeNode * root); //used to print black nodes
		void printBlackNodes(TreeNode * root); //used to print red nodes
		
		TreeNode * getRoot();

	private:	
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
		void recolor(TreeNode *& node);
		
		BinarySearchTree bst_;
		
};

#endif
