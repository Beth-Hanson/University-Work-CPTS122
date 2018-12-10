/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: Stack.h
Date: 10/30/18
Description: */

#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class Stack {
public:
	Stack(int newSize = 0);
	~Stack();
	void peek(string &newString);
	void push(string &newString);
	void pop(string &popString);
	bool isEmpty();

private:
	int size;
	int maxSize;
	string *top;
};