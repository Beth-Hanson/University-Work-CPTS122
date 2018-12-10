/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 5
File: Data.cpp
Date: 10/15/18
Description: */

#include "Data.h"

Data::Data() {
	this->customerNumber = 0;
	this->serviceTime = 0;
	this->totalTime = 0;
}

Data::Data(int &newCustNum, int &newServTime, int &newTotTime) {
	this->customerNumber = newCustNum;
	this->serviceTime = newServTime;
	this->totalTime = newTotTime;
}

Data::Data(Data &copy) {
	this->customerNumber = copy.getCustNum();
	this->serviceTime = copy.getServTime();
	this->totalTime = copy.getTotTime();
}

Data::~Data() {

}

//Data & Data::operator=(Data & rhs) {
//    if (this != &rhs){
//		this->customerNumber = rhs.getCustNum();
//		this->serviceTime = rhs.getServTime();
//		this->totalTime = rhs.getTotTime();
//	}
//	return *this;
//}

int Data::getCustNum() {
	return this->customerNumber;
}

int Data::getServTime() {
	return this->serviceTime;
}

int Data::getTotTime() {
	return this->totalTime;
}

void Data::setCustNum(int &newCustNum) {
	this->customerNumber = newCustNum;
}

void Data::setServTime(int &newServTime) {
	this->serviceTime = newServTime;
}

void Data::setTotTime(int &newTotTime) {
	this->totalTime = newTotTime;
}

void Data::decreaseServTime() {
	this->serviceTime--;
}

bool operator==(Data & lhs, Data & rhs) {
	bool success = false;
	if (lhs.getCustNum() == rhs.getCustNum() && lhs.getServTime() == rhs.getServTime() && lhs.getTotTime() == rhs.getTotTime()) {
		success = true;
	}
	return success;
}
