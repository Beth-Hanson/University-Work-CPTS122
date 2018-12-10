/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: Node.h
Date: 11/15/18
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

class Node {
public:
	Node(const string &newData = "");
	virtual ~Node();
	void setData(const string &newData);
	void setLeft(Node *newLeft);
	void setRight(Node *newRight);
	string getData();
	Node *&getLeft();
	Node *&getRight();
	virtual void printData();

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};