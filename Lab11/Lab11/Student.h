#pragma once
#include "person.h"

struct Course {
	string name;
	int credits;
	char grade;
};

class Student : public Person {
public:
	Student();

private:
	Course schedule[5];
	int numCourses;
	int totalCredits;
};

