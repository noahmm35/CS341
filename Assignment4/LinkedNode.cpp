// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "LinkedNode.h"

LinkedNode::LinkedNode() : LinkedNode(0,nullptr,nullptr)
{

}

LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode)
{
	Node n(data);
	data_=data;
	nextLinkedNode_=nextLinkedNode;
	prevLinkedNode_=prevLinkedNode;
}

LinkedNode::~LinkedNode()
{
	delete nextLinkedNode_;
}

LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
	nextLinkedNode_=nextLinkedNode;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_=prevLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
	if (nextLinkedNode_!=nullptr)
		return 1;
	else
		return 0;
}

bool LinkedNode::hasPrevLinkedNode()
{
	if (prevLinkedNode_!=nullptr)
		return 1;
	else
		return 0;
}

int LinkedNode::getData()
{
	return data_;
}
