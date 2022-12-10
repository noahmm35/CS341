// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	root_ = insertNode(root_, newNode);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	// If the BST is empty - go ahead and make the node the root.
	if (root == nullptr)
	{
		node->setColor(black);
		return node;
	}
	else
	{
		// Determine which subtree to insert the node into...
		if (node->getData() < root->getData()) 
		{ 
			// Left Subtree
			root->setLeftChild(insertNode(root->getLeftChild(), node)); 
			root->getLeftChild()->setParent(root); 
			node->setColor(red);
		} 
		else 
		{ 
			// Right Subtree
			root->setRightChild(insertNode(root->getRightChild(), node)); 
			root->getRightChild()->setParent(root); 
			node->setColor(red);
		}
		
		
		return root;
	}	
}

void BinarySearchTree::inOrder(TreeNode * root)
{
	//Left Subtree -> Root -> Right Subtree

	if(root == nullptr)
	{
		return;
	}
	
	inOrder(root->getLeftChild());
	
	std::cout << root->getData() << " ";

	inOrder(root->getRightChild());
}

void BinarySearchTree::preOrder(TreeNode * root)
{
	//Root -> Left -> Right
	
	if(root == nullptr)
	{
		return;
	}
	
	std::cout << root->getData() << " ";
	
	preOrder(root->getLeftChild());
	
	preOrder(root->getRightChild());
}

void BinarySearchTree::postOrder(TreeNode * root)
{
	// Left -> Right -> Root
	
	if(root == nullptr)
	{
		return;
	}
	
	postOrder(root->getLeftChild());
	
	postOrder(root->getRightChild());
	
	std::cout << root->getData() << " ";
}
