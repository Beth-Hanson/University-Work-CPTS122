#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;

class Person {
public:
	Person(string newName = "", int newAge = 0, 
		string newGender = "", int newHeight = 0);
	Person(Person &copy);
	~Person();
	Person &operator=(Person &rhs);
	string getName();
	int getAge();
	string getGender();
	int getHeight();

	void setName(string newName);
	void setAge(int newAge);
	void setGender(string newGender);
	void setHeight(int newHeight);


protected:
	string name;
	int age;
	string gender;
	int height;
};

ostream &operator<<(ostream &lhs, Person &rhs);
istream &operator>>(istream &lhs, Person &rhs);