/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: Student.cpp
Date: 10/30/18
Description: */

#include "Student.h"

Data::Data(int const &newID, int const &newRecord, string const &newName, int const &newUnit, 
	string const &newEmail, string const &newMajor, string const &newLevel, int const &absences) {
	this->recordNum = newRecord;
	this->mID = newID;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnit;
	this->mMajor = newMajor;
	this->mLevel = newLevel;
	this->mAbsences = absences;
}

Data::~Data() {
}

int Data::getID() {
	return this->mID;
}

int Data::getRecordNum()
{
	return this->recordNum;
}

string Data::getName() {
	return this->mName;
}

string Data::getEmail() {
	return this->mEmail;
}

int Data::getUnits() {
	return this->mUnits;
}

string Data::getMajor() {
	return this->mMajor;
}

string Data::getLevel() {
	return this->mLevel;
}

int Data::getAbsences() {
	return this->mAbsences;
}

void Data::peekDate(string &date) {
	this->mDates->peek(date);
}

void Data::setID(int newID) {
	this->mID = newID;
}

void Data::setRecordNum(int newNum) {
	this->recordNum = newNum;
}

void Data::setName(string newName) {
	this->mName = newName;
}

void Data::setEmail(string newEmail) {
	this->mEmail = newEmail;
}

void Data::setUnits(int newUnits) {
	this->mUnits = newUnits;
}

void Data::setMajor(string newMajor) {
	this->mMajor = newMajor;
}

void Data::setLevel(string newLevel) {
	this->mLevel = newLevel;
}

void Data::setAbsences(int newAbsences) {
	this->mAbsences = newAbsences;
}

void Data::pushDate(string newDate) {
	this->mDates->push(newDate);
}

void Data::popDate(string & date) {
	this->mDates->pop(date);
}
