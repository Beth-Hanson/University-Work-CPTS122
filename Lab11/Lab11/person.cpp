#include "person.h"

Person::Person(string newName, int newAge, string newGender, int newHeight) {
	this->name = newName;
	this->age = newAge;
	this->height = newHeight;
	this->gender = newGender;
}

Person::Person(Person & copy) {
	this->age = copy.age;
	this->gender = copy.gender;
	this->height = copy.height;
	this->name = copy.name;
}

Person::~Person() {

}

Person & Person::operator=(Person & rhs) {
	this->age = rhs.age;
	this->name = rhs.name;
	this->gender = rhs.gender;
	this->height = rhs.height;
}

string Person::getName() {
	return this->name;
}

int Person::getAge() {
	return this->age;
}

string Person::getGender() {
	return this->gender;
}

int Person::getHeight() {
	return this->height;
}

void Person::setName(string newName) {
	this->name = newName;
}

void Person::setAge(int newAge) {
	this->age = newAge;
}

void Person::setGender(string newGender) {
	this->gender = newGender;
}

void Person::setHeight(int newHeight) {
	this->height = newHeight;
}

ostream & operator<<(ostream & lhs, Person &rhs) {
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Age: " << rhs.getAge() << endl;
	lhs << "Gender: " << rhs.getGender() << endl;
	lhs << "Height: " << rhs.getHeight() << endl;
	return lhs;
}

istream & operator>>(istream & lhs, Person &rhs) {
	int input = 0;
	string intake = "";
	lhs >> intake;
	rhs.setName(intake);
	lhs >> input;
	rhs.setAge(input);
	lhs >> intake;
	rhs.setGender(intake);
	lhs >> input;
	rhs.setHeight(input);
	return lhs;
}


