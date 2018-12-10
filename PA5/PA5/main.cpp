/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: main.cpp
Date: 10/15/18
Description: */

#include "Data.h"
#include "Node.h"
#include "Queue.h"
#include "Test.h"

int main() {
	QueueTest test;
	test.testEmptyEnqueue();
	test.testOneEnqueue();
	test.testOneDequeue();
	test.testTwoDequeue();
	test.testRun();
	runSim(31);

	system("pause");
	return 0;
}