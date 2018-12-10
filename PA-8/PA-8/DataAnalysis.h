/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: DataAnalysis.h
Date: 11/15/18
Description: */

#pragma once
#include "BST.h"

class DataAnalysis {
public:
	DataAnalysis();
	~DataAnalysis();
	void runAnalysis();
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
	ifstream &openFile();
	void fileLinetoTree(int *units, string *type, string *transaction);
	void soldOrPurchased(int *units, string *type, string *transaction);
	void displayTrees(int *units, string *type, string *transaction);
	void leastAndMost();
};