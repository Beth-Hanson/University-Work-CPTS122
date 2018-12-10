/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: TransactionNode.cpp
Date: 11/15/18
Description: */

#include "TransactionNode.h"

TransactionNode::~TransactionNode()
{
}

void TransactionNode::setUnits(const int & newUnits) {
	this->mUnits = newUnits;
}

int TransactionNode::getUnits() {
	return this->mUnits;
}

void TransactionNode::printData() {
	cout << this->mData << endl;
	cout << this->mUnits << endl;
}
