/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Data.h
Date: 10/15/18
Description: */

#pragma once
#pragma warning(disable: 4996)

//Libraries
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

class Data {
public:
	Data();
	Data(int &newCustNum, int &newServTime, int &newTotTime);
	Data(Data &copy);
	~Data();
	//Data & operator= (Data &rhs);

	int getCustNum();
	int getServTime();
	int getTotTime();

	void setCustNum(int &newCustNum);
	void setServTime(int &newServTime);
	void setTotTime(int &newTotTime);
	void decreaseServTime();

private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};

bool operator==(Data &lhs, Data &rhs);