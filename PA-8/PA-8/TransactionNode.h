/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: TransactionNode.h
Date: 11/15/18
Description: */

#include "Node.h"

#pragma once

class TransactionNode : public Node {
public:
	TransactionNode(const string &newData = "",
		const int &newUnits = 0) : Node(newData) {
		this->mUnits = newUnits;
	}
	~TransactionNode();
	void setUnits(const int &newUnits);
	int getUnits();
	void printData();
private:
	int mUnits;
};