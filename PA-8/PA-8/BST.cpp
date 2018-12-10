#include "BST.h"

BST::BST() {
	this->mpRoot = nullptr;
}

BST::~BST() {
	destroyTree(this->mpRoot);
}

void BST::setRoot(Node * newRoot) {
	this->mpRoot = newRoot;
}

Node * BST::getRoot() {
	return this->mpRoot;
}

void BST::inOrderTraversal() {
	inOrderTraversal(this->mpRoot);
}

TransactionNode & BST::findSmallest(Node *pNode) {
	TransactionNode *pTemp = dynamic_cast<TransactionNode*>(pNode);
	if (pTemp->getLeft() != nullptr) {
		return findSmallest(pTemp->getLeft());
	}
	return *pTemp;
}

TransactionNode & BST::findLargest(Node *pNode) {
	TransactionNode *pTemp = dynamic_cast<TransactionNode*>(pNode);
	if (pTemp->getRight() != nullptr) {
		return findLargest(pTemp->getRight());
	}
	return *pTemp;
}

void BST::destroyTree(Node *pNode) {
	if (pNode->getLeft() != nullptr) {
		destroyTree(pNode->getLeft());
		pNode->setLeft(nullptr);
	}
	if (pNode->getRight() != nullptr) {
		destroyTree(pNode->getRight());
		pNode->setRight(nullptr);
	}
	if (pNode->getRight() == nullptr && pNode->getLeft() == nullptr) {
		delete pNode;
	}
}

void BST::inOrderTraversal(Node * pNode) {
	TransactionNode *pTemp = dynamic_cast<TransactionNode*>(pNode);
	if (pTemp != nullptr) {
		inOrderTraversal(pTemp->getLeft());
		pTemp->printData();
		inOrderTraversal(pTemp->getRight());
	}
}

void BST::insert(string & newData, int &newUnits) {
	insert(this->mpRoot, newData, newUnits);
}

void BST::insert(Node * &pTree, string & newData, int &newUnits) {
	TransactionNode * pTemp = dynamic_cast<TransactionNode*>(pTree);
	if (pTemp != nullptr) {
		if (newUnits>pTemp->getUnits()) {
			if (pTemp->getRight() == nullptr) {
				pTemp->setRight(new TransactionNode(newData, newUnits));
			}
			else {
				insert(pTemp->getRight(), newData, newUnits);
			}
		}
		if (newUnits < pTemp->getUnits()) {
			if (pTemp->getLeft() == nullptr) {
				pTemp->setLeft(new TransactionNode(newData, newUnits));
			}
			else {
				insert(pTemp->getLeft(), newData, newUnits);
			}
		}
	}
	else {
		this->mpRoot = new TransactionNode(newData, newUnits);
	}
	
}
