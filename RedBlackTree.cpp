// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	bst_.setRoot(nullptr);
}

void RedBlackTree::insert(int data)
{	
	TreeNode * newNode = new TreeNode(data);
	bst_.setRoot(bst_.insertNode(bst_.getRoot(), newNode));

	if(bst_.getRoot()!=newNode)
	{
		TreeNode * p = newNode->getParent();
		balanceColor(p,newNode);
	}
}

TreeNode * RedBlackTree::getRoot()
{
	return bst_.getRoot();
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{	
	root->setRightChild(newNode->getLeftChild());
	
	if(newNode->getLeftChild() != nullptr)
		newNode->getLeftChild()->setParent(root);
		
	newNode->setParent(root->getParent());
	
	if(root->getParent()==nullptr)
		bst_.setRoot(newNode);
	else if(root->getParent()->getLeftChild() == root)
		root->getParent()->setLeftChild(newNode);
	else if(root->getParent()->getLeftChild() != root)
		root->getParent()->setRightChild(newNode);
	else
		std::cout << "we should not be here" << std::endl;
		
	newNode->setLeftChild(root);
	root->setParent(newNode);
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	root->setLeftChild(newNode->getRightChild());
	
	if(newNode->getRightChild() != nullptr)
		newNode->getRightChild()->setParent(root);
	
	newNode->setParent(root->getParent());
	
	if(root->getParent() == nullptr) //root is root of entire tree
		bst_.setRoot(newNode);
	else if (root->getParent()->getLeftChild() == root)
		root->getParent()->setLeftChild(newNode);
	else if (root->getParent()->getLeftChild() != root)
		root->getParent()->setRightChild(newNode);
	else
		std::cout << "we should not be here" << std::endl;
	
	newNode->setRightChild(root);
	root->setParent(newNode);
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{	
	while(root->getColor() == 1) //loop stops when newNode becomes the root or when the parent of newNode is black
	{
		TreeNode * grandparent = root->getParent();
		TreeNode * uncle = root->getParent()->getRightChild();
		
		
		if(root->getParent()->getLeftChild() != root)
			uncle = root->getParent()->getLeftChild();
		
		if(uncle != nullptr && uncle->getColor() == 1)
			recolor(newNode);
			
		else
		{
			if(root->getParent()->getLeftChild() == root && newNode->getParent()->getLeftChild() == newNode) //left left case #
			{
				rotateRight(grandparent, root);
				root->flipColor();
				grandparent->flipColor();
			}
			else if(root->getParent()->getLeftChild() == root && newNode->getParent()->getLeftChild() != newNode) //left right case
			{
				rotateLeft(root, newNode);
				
				TreeNode * temp = newNode;
				newNode = root;
				root=temp;
				
				rotateRight(grandparent, root);
				root->flipColor();
				grandparent->flipColor();
			}
			else if(root->getParent()->getLeftChild() != root && newNode->getParent()->getLeftChild() == newNode) //right left case
			{
				rotateRight(root, newNode);
				
				TreeNode * temp = newNode;
				newNode = root;
				root=temp;
				
				rotateLeft(grandparent, root);
				root->flipColor();
				grandparent->flipColor();
			}
			else if(root->getParent()->getLeftChild() != root && newNode->getParent()->getLeftChild() != newNode) //right right case #
			{
				rotateLeft(grandparent, root);
				root->flipColor();
				grandparent->flipColor();
			}
			else
				std::cout << "This shouldn't happen... oops ..." << std::endl;
		}
	}
	bst_.getRoot()->setColor(black);
	
	/* if(root!=bst_.getRoot()) //will cause recursion to balance each subtree until we reach the root of entire tree
	{
		TreeNode * grandparent = root->getParent();
		balanceColor(grandparent,root);
	} */
}

void RedBlackTree::recolor(TreeNode *& node) //will recolor parent, uncle, and grandparent recursively up the tree
{
	TreeNode * parent = node->getParent();
	
	if(parent != nullptr)
	{
		parent->flipColor();
		TreeNode * grandparent = parent->getParent();
		
		if(grandparent != nullptr)
		{
			grandparent->flipColor();
			
			TreeNode * uncle = grandparent->getLeftChild();
			if(parent==uncle)
				uncle = grandparent->getRightChild();
			
			if(uncle!=nullptr)
				uncle->flipColor();
			
			recolor(grandparent);
		}
	}
}

void RedBlackTree::printRedNodes(TreeNode * root)
{
	//utilize inorder
	if(root == nullptr)
	{
		return;
	}
	
	printRedNodes(root->getLeftChild());
	
	if(root->getColor()==1)
		std::cout << root->getData() << " ";

	printRedNodes(root->getRightChild());
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
	//utilize preorder
	if(root == nullptr)
	{
		return;
	}
	
	if(root->getColor()==2)
		std::cout << root->getData() << " ";
	
	printBlackNodes(root->getLeftChild());
	
	printBlackNodes(root->getRightChild());
}