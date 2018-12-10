/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Test.h
Date: 10/15/18
Description: */

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Queue.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class QueueTest {
public:
	void testEmptyEnqueue();
	void testOneEnqueue();
	void testOneDequeue();
	void testTwoDequeue();
	void testRun();
private:
	Queue test;
};