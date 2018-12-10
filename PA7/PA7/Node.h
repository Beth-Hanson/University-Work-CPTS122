/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: Node.h
Date: 10/30/18
Description: */

#pragma once
#include "Student.h"

template<class T>
class Node {
public:
	Node();
	~Node();
	Node(T &newData);
	T getData();
	Node<T> *getNext();
	void setData(T &newData);
	void setNext(Node<T> *newNext);

private:
	T pData;
	Node *pNext;
};

template<class T>
Node<T>::Node() {
	this->pNext = nullptr;
}

template<class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>::Node(T & newData) {
	this->pData = newData;
	this->pNext = nullptr;
}

template<class T>
T Node<T>::getData() {
	return this->pData;
}

template<class T>
Node<T>* Node<T>::getNext() {
	return this->pNext;
}

template<class T>
void Node<T>::setData(T & newData) {
	this->pData = newData;
}

template<class T>
void Node<T>::setNext(Node<T>* newNext) {
	this->pNext = newNext;
}
