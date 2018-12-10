/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 6
File: BST.cpp
Date: 10/22/18
Description: */

#include "BST.h"

BST::BST() {
	fstream infile;
	char alpha;
	string morse;
	infile.open("MorseTable.txt", std::fstream::in);
	while (!infile.eof()) {
		infile >> alpha;
		infile >> morse;
		insert(this->pRoot, alpha, morse);
	}
	infile.close();
}

BST::~BST() {
	this->destroyTree(this->pRoot);
}

BSTNode * BST::getRoot() {
	return this->pRoot;
}

void BST::insert(BSTNode *pTree, char &newAlpha, string &newString) {
	if (pTree != nullptr) {
		if (newAlpha > pTree->getAlpha()) {
			if (pTree->getRight() == nullptr) {
				pTree->setRight(new BSTNode(newAlpha, newString));
			}
			else  {
				insert(pTree->getRight(), newAlpha, newString);
			}

		}

		else if (newAlpha < pTree->getAlpha()) {
			if (pTree->getLeft() != nullptr) {
				insert(pTree->getLeft(), newAlpha, newString);
			}
			else {
				pTree->setLeft(new BSTNode(newAlpha, newString));
			}
		}
	}
	else {
		this->pRoot = new BSTNode(newAlpha, newString);
	}
}

void BST::print(BSTNode *pTree) {
	if (pTree != nullptr) {
		print(pTree->getLeft());
		cout << pTree->getAlpha() << " ";
		cout << pTree->getMorse() << " ";
		print(pTree->getRight());
	}
}

string BST::search(BSTNode *pTree, char & targetAlpha) {
	string morse;
	char treeAlpha = '\0';
	if (pTree != nullptr) {
		if (targetAlpha == pTree->getAlpha()) {
			morse = pTree->getMorse();
			treeAlpha = pTree->getAlpha();
			return morse;
		}
		if (targetAlpha > pTree->getAlpha()) {
			return search(pTree->getRight(), targetAlpha);
		}
		if (targetAlpha < pTree->getAlpha()) {
			return search(pTree->getLeft(), targetAlpha);
		}
	}
	else {
		return morse;
	}
}

void BST::destroyTree(BSTNode * pNode) {
	if (pNode != nullptr) {
		destroyTree(pNode->getLeft());
		destroyTree(pNode->getRight());
		if (pNode->getRight() != nullptr) {
			pNode->setRight(nullptr);
		}
		if (pNode->getLeft() != nullptr) {
			pNode->setLeft(nullptr);
		}
	}
	else {
		delete pNode;
	}
	//if (pNode->getLeft() != nullptr) {
	//	destroyTree(pNode->getLeft());
	//	pNode->setLeft(nullptr);
	//}
	//if (pNode->getRight() != nullptr) {
	//	destroyTree(pNode->getRight());
	//	pNode->setRight(nullptr);
	//}
	//if (pNode->getRight() == nullptr && pNode->getLeft() == nullptr) {
	//	delete pNode;
	//}
}

void toUpper(char * input_char) {
	if (*input_char > 96 && *input_char < 123) {
		*input_char = *input_char - 32;
	}
}