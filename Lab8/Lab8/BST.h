#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <string>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;

using std::iostream;
using std::ostream;
using std::istream;
using std::string;

class BST {
public:
	BST();
	BSTNode *getRoot();
	void insertNode(BSTNode *pNode, string const &newData);
	void inOrderTraversal(BSTNode *pNode);
	void preOrderTraversal(BSTNode *pNode);
	void postOrderTraversal(BSTNode *pNode);
	bool isEmpty();
	void destroyTree(BSTNode *pNode);

private:
	BSTNode *mRoot;
};

ostream &operator<<(ostream &lhs, BSTNode &rhs);