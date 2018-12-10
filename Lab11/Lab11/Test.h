#pragma once
#include "person.h"

class TestPerson : public Person {
public:
	void testConstructor();
	void testCopy();
	void testOperators();
	void testGetName();
	void testGetAge();
	void testGetGender();
	void testGetHeight();

	void testSetName();
	void testSetAge();
	void testSetGender();
	void testSetHeight();
};