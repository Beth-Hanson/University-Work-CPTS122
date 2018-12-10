#include "Test.h"

void TestPerson::testConstructor() {
	Person test;
	if (test.getName() == "" && test.getAge() == 0 && test.getGender() == ""
		&& test.getHeight() == 0) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testCopy() {
	Person copy("Copy Copy", 0, "copy", 0);
	Person test(copy);
	if (copy.getName() == test.getName() && copy.getAge() == test.getAge() && copy.getGender() == test.getGender()
		&& copy.getHeight() == test.getHeight()){
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" <<endl;
	}
}

void TestPerson::testOperators() {
	Person test;
	Person copy("Copy Copy", 0, "copy", 0);
	test = copy;
	if (test.getName() == copy.getName()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
	if (cout << test) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
	if (cin >> test) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testGetName() {
	string test;
	test = this->getName();
	if (test == this->getName()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testGetAge() {
	int test;
	test = this->getAge();
	if (test == this->getAge()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testGetGender() {
	string test;
	test = this->getGender();
	if (test == this->getGender()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testGetHeight() {
	int test;
	test = this->getHeight();
	if (test == this->getHeight()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testSetName() {
	string test = "Test test";
	this->setName(test);
	if (test == this->getName()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testSetAge() {
	int test = 99;
	this->setAge(test);
	if (test == this->getAge()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testSetGender() {
	string test = "Test test";
	this->setGender(test);
	if (test == this->getGender()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}

void TestPerson::testSetHeight() {
	int test = 99;
	this->setHeight(test);
	if (test == this->getHeight()) {
		cout << "test case passed" << endl;
	}
	else {
		cout << "test case failed" << endl;
	}
}
