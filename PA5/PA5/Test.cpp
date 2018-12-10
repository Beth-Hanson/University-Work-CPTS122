/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Test.cpp
Date: 10/15/18
Description: */

#include "Test.h"

void QueueTest::testEmptyEnqueue() {
	Data testData;
	int num = 1;
	testData.setCustNum(num);
	testData.setServTime(num);
	testData.setTotTime(num);
	this->test.enqueue(&testData);
	if (test.getTail() == test.getHead()) {
		cout << "Test: Successfully Enqueued an Empty List" << endl;
	}
	else {
		cout << "Test: Failed to Enqueue an Empty List" << endl;
	}
	test.~Queue();
}

void QueueTest::testOneEnqueue() {
	Data testData, testData2;
	int num = 1, num2 = 2;
	testData.setCustNum(num);
	testData.setServTime(num);
	testData.setTotTime(num);
	testData2.setCustNum(num2);
	testData2.setServTime(num2);
	testData2.setTotTime(num2);
	this->test.enqueue(&testData);
	this->test.enqueue(&testData2);
	if (testData2 == *test.getTail()->getData() && testData == *test.getHead()->getData()) {
		cout << "Test: Successfully Enqueued a Node" << endl;
	}
	else {
		cout << "Test: Failed to Enqueue a Node" << endl;
	}
	this->test.~Queue();
}

void QueueTest::testOneDequeue() {
	Data testData;
	Data dequeueData;
	int num = 1;
	testData.setCustNum(num);
	testData.setServTime(num);
	testData.setTotTime(num);
	this->test.enqueue(&testData);
	dequeueData = this->test.dequeue();
	if (testData == dequeueData) {
		if (this->test.getTail() == nullptr) {
			cout << "Test: Successfully dequeued" << endl;
		}
		else {
			cout << "Test: Magic?" << endl;
		}
	}
	else {
		cout << "Test: Failed to dequeue" << endl;
	}
	this->test.~Queue();
}

void QueueTest::testTwoDequeue() {
	Data testData, testData2;
	Data dequeueData;
	int num = 1, num2 = 2;
	testData.setCustNum(num);
	testData.setServTime(num);
	testData.setTotTime(num);
	testData2.setCustNum(num2);
	testData2.setServTime(num2);
	testData2.setTotTime(num2);
	this->test.enqueue(&testData);
	this->test.enqueue(&testData2);
	this->test.dequeue();
	if (test.getTail() == test.getHead()) {
		cout << "Test: Successfully dequeued" << endl;
	}
	else {
		cout << "Test: Failed to dequeue" << endl;
	}
	test.~Queue();
}

void QueueTest::testRun() {
	runSim(1440);
}

