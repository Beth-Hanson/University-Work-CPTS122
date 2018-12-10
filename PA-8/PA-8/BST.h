/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: BST.h
Date: 11/15/18
Description: */

#include "TransactionNode.h"
#pragma once

class BST {
public:
	BST();
	~BST();
	void insert(string &newData, int &newUnits);
	void setRoot(Node *newRoot);
	Node *getRoot();
	void inOrderTraversal();
	TransactionNode &findSmallest(Node *pNode);
	TransactionNode &findLargest(Node *pNode);

private:
	Node * mpRoot;
	void destroyTree(Node *pNode);
	void inOrderTraversal(Node *pNode);
	void insert(Node *&pTree, string &newData, int &newUnits);
};