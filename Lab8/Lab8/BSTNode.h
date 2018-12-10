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

class BSTNode {
public:
	BSTNode(string const &newData);
	string getData();
	BSTNode *getLeft();
	BSTNode *getRight();
	void setData(string const &newData);
	void setNewLeft(BSTNode * const &newLeft);
	void setNewRight(BSTNode * const &newRight);

private:
	string mData;
	BSTNode *pLeft;
	BSTNode *pRight;
};