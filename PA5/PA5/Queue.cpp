/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Queue.cpp
Date: 10/15/18
Description: */

#include "Queue.h"

Queue::Queue(QueueNode * newHead, QueueNode * newTail) {
	this->pHead = newHead;
	this->pTail = newTail;
}

Queue::~Queue(){
	while (this->pHead != nullptr) {
		this->dequeue();
	}
}

void Queue::enqueue(Data *newData) {
	QueueNode *pTemp = new QueueNode(*newData);
	if (pTemp != nullptr) {
		if (this->pHead == nullptr) {
			this->setHead(pTemp);
			this->setTail(pTemp);
		}
		else {
			this->pTail->setNext(pTemp);
			this->setTail(pTemp);
		}
	}
}

Data Queue::dequeue() {
	Data returnData;
	QueueNode *pTemp = nullptr;
	pTemp = this->pHead;
	returnData = *this->pHead->getData();
	if (this->pHead == this->pTail) {
		this->pHead = this->pTail = nullptr;
	}
	else {
		this->setHead(this->pHead->getNext());
	}
	delete pTemp;

	return returnData;
}

void Queue::printQueue() {
	if (this->pHead != nullptr) {
		QueueNode *pTemp;
		if (this->pHead == this->pTail) {
			pTemp = this->getHead();
			cout << "Customer Number: " << pTemp->getData()->getCustNum() << endl;
			cout << "Service Time: " << pTemp->getData()->getServTime() << endl;
			cout << "Total Time: " << pTemp->getData()->getTotTime() << endl;
			cout << endl;
		}
		else {
			pTemp = this->getHead();
			while (pTemp->getNext() != nullptr) {
				cout << "Customer Number: " << pTemp->getData()->getCustNum() << endl;
				cout << "Service Time: " << pTemp->getData()->getServTime() << endl;
				cout << "Total Time: " << pTemp->getData()->getTotTime() << endl;
				cout << endl;
				pTemp = pTemp->getNext();
			}
		}
	}
	else {
		cout << "Empty List" << endl;
	}
	
}

void Queue::setHead(QueueNode * newHead) {
	this->pHead = newHead;
}

void Queue::setTail(QueueNode * newTail) {
	this->pTail = newTail;
}

QueueNode * Queue::getHead()
{
	return this->pHead;
}

QueueNode * Queue::getTail()
{
	return this->pTail;
}

//ostream & operator <<(ostream & lhs, QueueNode & rhs) {
//	lhs << "Customer Number: " << rhs.getData()->getCustNum() << endl;
//	lhs << "Service Time: " << rhs.getData()->getServTime() << endl;
//	lhs << "Total Time: " << rhs.getData()->getTotTime() << endl;
//	return lhs;
//}

void runSim(int minutes) {
	Queue express, normal;
	int exService, exTotal, normServ, normTot, custNum;
	int addExCustomer = (rand() % 5) + 1;
	int addNormCustomer = (rand() % 5) + 3;
	for (int i = 0; i < minutes; i++) {
		Data exCustomer;
		Data normCustomer;
		Data returnData;
		custNum = i;
		exCustomer.setCustNum(custNum);
		exService = (rand() % 5) + 1;
		exCustomer.setServTime(exService); 
		if (express.getHead() != nullptr) {
			exTotal = exService + express.getTail()->getData()->getTotTime();
		}
		else {
			exTotal = exService;
		}
		exCustomer.setTotTime(exTotal);
		normCustomer.setCustNum(custNum);
		normServ = (rand() % 5) + 3;
		normCustomer.setServTime(normServ);
		if (normal.getHead() != nullptr) {
			normTot = normServ + normal.getTail()->getData()->getTotTime();
		}
		else {
			normTot = normServ;
		}
		normCustomer.setTotTime(normTot);
		if (express.getHead() != nullptr) {
			express.getHead()->getData()->decreaseServTime();
			if (express.getHead()->getData()->getServTime() == 0) {
				returnData = express.dequeue();
			}
		}
		if (normal.getHead() != nullptr) {
			normal.getHead()->getData()->decreaseServTime();
			if (normal.getHead()->getData()->getServTime() == 0) {
				returnData = normal.dequeue();
			}
		}
		if (addExCustomer == 0) {
			express.enqueue(&exCustomer);
			addExCustomer = (rand() % 5) + 1;
		}
		if (addNormCustomer == 0) {
			normal.enqueue(&exCustomer);
			addNormCustomer = (rand() % 5) + 3;
		}
	
		if ((i % 10) == 0) {
			cout << "Express Line" << endl;
			express.printQueue();
			cout << "Normal Line" << endl;
			normal.printQueue();
		}
		addExCustomer--;
		addNormCustomer--;
	}
	express.~Queue();
	normal.~Queue();
}
