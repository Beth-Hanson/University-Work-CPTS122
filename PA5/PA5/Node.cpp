/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Node.cpp
Date: 10/15/18
Description: */

#include "Node.h"

QueueNode::QueueNode() {
	this->pNext = nullptr;
	this->pData = nullptr;
}

QueueNode::~QueueNode() {
	delete this->pData;
}

QueueNode::QueueNode(Data & newData) {
	this->pNext = nullptr;
	this->pData = new Data(newData);
}

Data * QueueNode::getData() {
	if (this == nullptr) {
		return nullptr;
	}
	return this->pData;
}

QueueNode * QueueNode::getNext() {
	return this->pNext;
}

void QueueNode::setData(Data & newData) {
	this->pData = new Data(newData);
}

void QueueNode::setNext(QueueNode *newNext) {
	this->pNext = newNext;
}
