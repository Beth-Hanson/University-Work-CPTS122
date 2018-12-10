/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: List.h
Date: 10/30/18
Description: */

#pragma once
#include "Node.h"
#include <ctime>
#include <iostream>
#include <sstream> // for ostringstream
#include <string>

template <class T>
class List {
public:
	List();
	~List();
	void insertAtFront(T newData);
	Node<T> *getHead();
	void setHead(Node<T> *newHead);
	void isAbsent();
	void printToFile(fstream &file);
	void generateReport(fstream &file);
	void generateAbsences(fstream &file);

private:
	Node<T> * pHead;
	void destroyList(Node<T> *pTemp);
};

template<class T>
List<T>::List() {
	this->pHead = nullptr;
}

template<class T>
List<T>::~List() {
	destroyList(this->pHead->getNext());
}

template<class T>
void List<T>::destroyList(Node<T> *pTemp) {
	if (pTemp != nullptr) {
		destroyList(pTemp->getNext());
		delete pTemp;
	}
}

template<class T>
void List<T>::insertAtFront(T newData) {
	Node<T> *pTemp = new Node<T>(newData);
	if (pTemp != nullptr) {
		pTemp->setNext(this->pHead);
		this->pHead = pTemp;
	}

}

template<class T>
Node<T>* List<T>::getHead() {
	return this->pHead;
}

template<class T>
void List<T>::setHead(Node<T> *newHead) {
	this->pHead = newHead;
}

template<class T>
void List<T>::isAbsent() {
	Node<Data> *pCur = this->pHead;
	Data tempStudent;
	fstream infile;
	fstream outfile;
	string name, date;
	char response;
	cout << "Y for Yes. N for No." << endl;
	while (pCur != nullptr) {
		name = pCur->getData().getName();
		cout << name << endl;
		cout << "Is this Person Absent?" << endl;
		cin >> response;
		if (response == 'Y' || response == 'y') {
			int absences = pCur->getData().getAbsences() + 1;
			tempStudent = pCur->getData();
			tempStudent.setAbsences(absences);
			std::time_t t = std::time(0);  
			std::tm* now = std::localtime(&t);
			std::ostringstream out;
			out << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday;
			tempStudent.pushDate(out.str());
			pCur->setData(tempStudent);
		}
		pCur = pCur->getNext();
	}
}

template<class T>
void List<T>::printToFile(fstream & file) {
	Node<Data> *pTemp = this->pHead;
	while (pTemp != nullptr) {
		file << pTemp->getData().getRecordNum() << ',';
		file << pTemp->getData().getID() << ',';
		file << pTemp->getData().getName() << ',';
		file << pTemp->getData().getEmail() << ',';
		file << pTemp->getData().getUnits() << ',';
		file << pTemp->getData().getMajor() << ',';
		file << pTemp->getData().getLevel() << endl;
		pTemp = pTemp->getNext();
	}
}

template<class T>
void List<T>::generateReport(fstream &file) {
	Node<Data> *pTemp = this->pHead;
	string date;
	file.open("report.txt", fstream::out);
	while (pTemp != nullptr) {
		file << "Record Number: " << pTemp->getData().getRecordNum() << ',';
		file << " ID: " << pTemp->getData().getID() << ',';
		file << " Name: " << pTemp->getData().getName() << ',';
		file << " Email: " << pTemp->getData().getEmail() << ',';
		file << " Units: " << pTemp->getData().getUnits() << ',';
		file << " Major: " << pTemp->getData().getMajor() << ',';
		file << " Level: " << pTemp->getData().getLevel() << ',';
		file << " Number of Absences: " << pTemp->getData().getAbsences() << ',';
		pTemp->getData().peekDate(date);
		file << " Last Day Absent: " << date << endl;
		pTemp = pTemp->getNext();
	}
	file.close();
}

template<class T>
void List<T>::generateAbsences(fstream &file) {
	int absthreshold = 0;
	Data temp;
	Node<Data> *pCur = this->pHead;
	cout << "Number of Absences as Threshold" << endl;
	cin >> absthreshold;
	file.open("absences.txt", fstream::out);
	while (pCur != nullptr) {
		temp = pCur->getData();
		if (temp.getAbsences() > absthreshold) {
			file << temp.getName() << endl;
		}
		pCur = pCur->getNext();
	}
	file.close();
}