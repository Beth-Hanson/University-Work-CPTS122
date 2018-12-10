/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 8
File: DataAnalysis.cpp
Date: 11/15/18
Description: */

#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() {

}

DataAnalysis::~DataAnalysis() {

}

ifstream &DataAnalysis::openFile() {
	this->mCsvStream.open("data.csv", ifstream::in);
	return this->mCsvStream;
}

void DataAnalysis::fileLinetoTree(int *units, string *type, string *transaction) {
	string line;
	getline(mCsvStream, line, ',');
	if (line != "\n" && line != "") {
		*units = stoi(line);
	}
	getline(mCsvStream, *type, ',');
	getline(mCsvStream, *transaction, '\n');
}

void DataAnalysis::soldOrPurchased(int * units, string * type, string * transaction) {
	if (*transaction == "Purchased") {
		this->mTreePurchased.insert(*type, *units);
	}
	if (*transaction == "Sold") {
		this->mTreeSold.insert(*type, *units);
	}
}

void DataAnalysis::displayTrees(int * units, string * type, string * transaction) {
	this->openFile();
	string line;
	getline(mCsvStream, line);
	while (!mCsvStream.eof()) {
		this->fileLinetoTree(units, type, transaction);
		this->soldOrPurchased(units, type, transaction);
	}
	mCsvStream.close();
	cout << "Sold BST" << endl;
	this->mTreeSold.inOrderTraversal();
	cout << endl << "Purchase BST" << endl;
	this->mTreePurchased.inOrderTraversal();
	cout << endl;
}

void DataAnalysis::leastAndMost() {
	TransactionNode *pSold = new TransactionNode();
	TransactionNode *pPurchased = new TransactionNode();
	cout << "Least Sold" << endl;
	*pSold = this->mTreeSold.findSmallest(mTreeSold.getRoot());
	pSold->printData();
	cout << endl << "Least Purchased" << endl;
	*pPurchased = this->mTreePurchased.findSmallest(mTreePurchased.getRoot());
	pPurchased->printData();
	cout << endl;
	cout << "Most Sold" << endl;
	*pSold = this->mTreeSold.findLargest(mTreeSold.getRoot());
	pSold->printData();
	cout << endl << "Most Purchased" << endl;
	*pPurchased = this->mTreePurchased.findLargest(mTreePurchased.getRoot());
	pPurchased->printData();
}

void DataAnalysis::runAnalysis() {
	int units = 0;
	string type = "", transaction = "";
	displayTrees(&units, &type, &transaction);
	leastAndMost();
}