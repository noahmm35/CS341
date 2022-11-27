// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "TreeNode.h"

TreeNode::TreeNode(int data)
{
	// We could also use the initialization list here...
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	color_= black;
}

TreeNode::~TreeNode()
{
	// Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

int TreeNode::getData()
{
	return data_;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

Color TreeNode::getColor()
{
	return color_;
}

void TreeNode::setColor(Color color)
{
	color_=color;
}

void TreeNode::flipColor()
{
	if(color_==2)
	{
		setColor(red);
	}
	else if(color_==1)
	{
		setColor(black);
	}
}