/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 6
File: BSTNode.cpp
Date: 10/22/18
Description: */

#include "BSTNode.h"

BSTNode::BSTNode(char &newAlpha, string &newMorse) {
	this->pLeft = nullptr;
	this->pRight = nullptr;
	this->alpha = newAlpha;
	this->morse = newMorse;
}

char BSTNode::getAlpha() {
	return this->alpha; 
}

string BSTNode::getMorse() {
	return this->morse;
}

BSTNode * BSTNode::getLeft() const {
	return this->pLeft;
}

BSTNode * BSTNode::getRight() const {
	return this->pRight;
}

void BSTNode::setAlpha(char &newAlpha) {
	this->alpha = newAlpha; 
}

void BSTNode::setMorse(string &newMorse) {
	this->morse = newMorse;
}

void BSTNode::setLeft(BSTNode * const &newLeft) {
	this->pLeft = newLeft;
}

void BSTNode::setRight(BSTNode * const &newRight) {
	this->pRight = newRight;
}