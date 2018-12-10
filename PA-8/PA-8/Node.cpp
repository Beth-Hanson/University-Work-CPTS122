/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: Node.cpp
Date: 11/15/18
Description: */

#include "Node.h"

Node::Node(const string & newData) {
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node() {

}

void Node::setData(const string & newData) {
	this->mData = newData;
}

void Node::setLeft(Node * newLeft) {
	this->mpLeft = newLeft;
}

void Node::setRight(Node *newRight) {
	this->mpRight = newRight;
}

string Node::getData() {
	return this->mData;
}

Node * &Node::getLeft()
{
	return this->mpLeft;
}

Node * &Node::getRight() {
	return this->mpRight;
}

void Node::printData() {
	cout << this->mData;
}
