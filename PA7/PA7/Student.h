/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: Student.h
Date: 10/30/18
Description: */

#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::iostream;
using std::fstream;
using std::string;

class Data {
public:
	Data(int const &newID = 0,int const &newRecord = 0, string const &newName = "", int const &newUnit = 0, 
		string const &newEmail = "", string const &newMajor = "", string const &newLevel = "", int const &absences = 0);
	~Data();

	int getID();
	int getRecordNum();
	string getName();
	string getEmail();
	int getUnits();
	string getMajor();
	string getLevel();
	int getAbsences();
	void peekDate(string &date);

	void setID(int newID);
	void setRecordNum(int newNum);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(int newUnits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);
	void setAbsences(int newAbsences);
	void pushDate(string newDate);
	void popDate(string &date);

private:
	int recordNum;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mMajor;
	string mLevel;
	int mAbsences; 
	Stack mDates[100];
};