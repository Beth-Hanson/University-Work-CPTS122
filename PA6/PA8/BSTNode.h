/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 6
File: BSTNode.h
Date: 10/22/18
Description: */

#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class BSTNode {
public:
	BSTNode(char &newAlpha, string &newMorse);
	char getAlpha();
	string getMorse();
	BSTNode * getLeft() const;
	BSTNode * getRight() const;
	void setAlpha(char &newAlpha);
	void setMorse(string &newMorse);
	void setLeft(BSTNode * const &newLeft);
	void setRight(BSTNode * const &newRight);

private:
	char alpha;
	string morse;
	BSTNode *pLeft;
	BSTNode *pRight;
};
