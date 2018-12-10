#include "BST.h"

BST::BST() {
	this->mRoot = nullptr;
}

BSTNode * BST::getRoot() {
	return this->mRoot;
}

void BST::insertNode(BSTNode *pNode, string const &newData) {
	if (pNode != nullptr) {
		if (newData > pNode->getData()) {
			if (pNode->getRight() == nullptr) {
				pNode->setNewRight(new BSTNode(newData));
			}
			else {
				insertNode(pNode->getRight(), newData);
			}
		}
		else if (newData < pNode->getData()) {
			if (pNode->getLeft() == nullptr) {
				pNode->setNewLeft(new BSTNode(newData));
			}
			else {
				insertNode(pNode->getLeft(), newData);
			}
		}
	}
	else {
		this->mRoot = new BSTNode(newData);
	}
}

void BST::inOrderTraversal(BSTNode * pNode) {
	if (pNode != nullptr) {
		inOrderTraversal(pNode->getLeft());
		cout << pNode->getData() << endl;
		inOrderTraversal(pNode->getRight());
	}
}

void BST::preOrderTraversal(BSTNode * pNode) {
	if (pNode != nullptr) {
		cout << pNode->getData() << endl;
		preOrderTraversal(pNode->getLeft());
		preOrderTraversal(pNode->getRight());
	}
}

void BST::postOrderTraversal(BSTNode * pNode) {
	if (pNode != nullptr) {
		postOrderTraversal(pNode->getLeft());
		postOrderTraversal(pNode->getRight());
		cout << pNode->getData() << endl;
	}
}

bool BST::isEmpty() {
	if (this->getRoot() == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void BST::destroyTree(BSTNode * pNode) {
	if (pNode->getLeft() != nullptr) {
		destroyTree(pNode->getLeft());
		pNode->setNewLeft(nullptr);
	}
	if (pNode->getRight() != nullptr) {
		destroyTree(pNode->getRight());
		pNode->setNewRight(nullptr);
	}
	if (pNode->getRight() == nullptr && pNode->getLeft() == nullptr) {
		delete pNode;
	}
}
