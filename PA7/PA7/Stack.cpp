/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: Stack.h
Date: 10/30/18
Description: */

#include "Stack.h"

Stack::Stack(int newSize) {
	this->maxSize = 100;
	this->size = newSize;
	this->top = new string[100];
}

Stack::~Stack() {
	if (size != 0) {
		delete[] this->top;
	}
}

void Stack::peek(string & newString) {
	if (!this->isEmpty()) {
		newString = this->top[this->size];
	}
}

void Stack::push(string & newString) {
	if (this->size < this->maxSize) {
		this->top[this->size] = newString;
		this->size++;
	}
}

void Stack::pop(string & popString) {
	if (!this->isEmpty()) {
		popString = this->top[this->size];
		this->size--;
	}
}

bool Stack::isEmpty() {
	bool success = false;
	if (this->top == nullptr) {
		success = true;
	}
	return success;
}
