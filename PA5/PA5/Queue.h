/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Queue.h
Date: 10/15/18
Description: */

#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Queue {
public:
	Queue(QueueNode *newHead = nullptr, QueueNode *newTail = nullptr);
	~Queue();
	void enqueue(Data *newData);
	Data dequeue();
	void printQueue();
	void setHead(QueueNode *newHead);
	void setTail(QueueNode *newTail);
	QueueNode *getHead();
	QueueNode *getTail();
	
private:
	QueueNode *pHead;
	QueueNode *pTail;
};

//ostream &operator<<(ostream &lhs, QueueNode &rhs);
void runSim(int minutes);
