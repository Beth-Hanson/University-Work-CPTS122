/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 6
File: BST.h
Date: 10/22/18
Description: */

#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <fstream>
#include <string>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class BST {
public:
	BST();
	~BST();
	BSTNode *getRoot();
	void insert(BSTNode *pTree, char &newAlpha, string &newString); 
	void print(BSTNode *pTree);
	string search(BSTNode *pTree, char & targetAlpha);

private:
	BSTNode *pRoot;
	void destroyTree(BSTNode * pNode);
};

void toUpper(char * input_char);