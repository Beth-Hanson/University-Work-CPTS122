/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 6
File: main.cpp
Date: 10/22/18
Description: */

#include "BSTNode.h"
#include "BST.h"

int main() {
	BST tree;
	fstream infile;
	char line[100];
	string morse;
	infile.open("Convert.txt", std::fstream::in);
	// for each line in file
	while (!infile.eof()) {
		infile.getline(line, 100);
		// for each character in line
		for (int i = 0; i < strlen(line); i++) {
			toUpper(&line[i]);
			// if space then space
			if (line[i] == ' ') {
				cout << "   ";
			}
			// else lookup in tree
			else {
				morse = tree.search(tree.getRoot(), line[i]);
				cout << morse << " ";
			}
		}
	}
	infile.close();
	tree.~BST();
	return 0;
}
