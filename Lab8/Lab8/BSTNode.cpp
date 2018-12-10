#include "BSTNode.h"

BSTNode::BSTNode(string const & newData) {
	this->pLeft = nullptr;
	this->pRight = nullptr;
	this->mData = newData;
}

string BSTNode::getData()
{
	return this->mData;
}

BSTNode *BSTNode::getLeft()
{
	return this->pLeft;
}

BSTNode *BSTNode::getRight()
{
	return this->pRight;
}

void BSTNode::setData(string const & newData) {
	this->mData = newData;
}

void BSTNode::setNewLeft(BSTNode * const & newLeft) {
	this->pLeft = newLeft;
}

void BSTNode::setNewRight(BSTNode * const & newRight) {
	this->pRight = newRight;
}

