/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 7
File: main.cpp
Date: 10/30/18
Description: */

#include "Student.h"
#include "List.h"
#include "Node.h"
#include "Stack.h"

int displayMenu();
void getFileLine(fstream &file, string *name, string *email, string *major, string *level, int *ID, int *record, int *units);
Data putRecord(string name, string email, string major, string level, int ID, int record, int units);

int main() {
	List<Data> masterList;
	Data student;
	int response = 0, response2 = 0, ID = 0, record = 0, units = 0;
	fstream infile;
	fstream outfile;
	string line, name, email, major, level;
	do {
		response = displayMenu();
		switch (response) {
		case 1:
			//import course list
			infile.open("classList.csv", fstream::in);
			getline(infile, line);
			while (!infile.eof()) {
				getFileLine(infile, &name, &email, &major, &level, &ID, &record, &units);
				student = putRecord(name, email, major, level, ID, record, units);
				if (student.getName() != "") {
					masterList.insertAtFront(student);
				}
			}
			infile.close();
			break;
		case 2:
			//load master list
			infile.open("master.txt", fstream::in);
			while (!infile.eof()) {
				getFileLine(infile, &name, &email, &major, &level, &ID, &record, &units);
				student = putRecord(name, email, major, level, ID, record, units);
				if (student.getName() != "") {
					masterList.insertAtFront(student);
				}
			}
			infile.close();
			break;
		case 3:
			//store master 
			outfile.open("master.txt", fstream::out);
			masterList.printToFile(outfile);
			outfile.close();
			break;
		case 4:
			//mark absences
			masterList.isAbsent();
			break;
		case 5:
			//bonus
			break;
		case 6:
			//generate report
			cout << "1. Generate Report of all Students" << endl;
			cout << "2. Generate Report of Absences" << endl;
			cin >> response2;
			system("cls");
			switch (response2) {
			case 1:
				//Report
				masterList.generateReport(outfile);
				break;
			case 2:
				//Absences
				masterList.generateAbsences(outfile);
				break;
			}
			break;
		case 7:
			//exit
			response = 8;
			break;
		}
	} while (response != 8);


	return 0;
}

int displayMenu() {
	int response = 0;
	cout << "1. Import Course List" << endl;
	cout << "2. Load Master List" << endl;
	cout << "3. Store Master List" << endl;
	cout << "4. Mark Absences" << endl;
	cout << "5. Bonus: Edit Absences" << endl;
	cout << "6. Generate Report" << endl;
	cout << "7. Exit" << endl;
	cin >> response;
	system("cls");
	return response;
}

void getFileLine(fstream &file, string *name, string *email, string *major, string *level, int *ID, int *record, int *units) {
	string line, name1, name2;
	string unit;
	getline(file, line, ',');
	if (line == "\n" || line == "") {
		*name = "";
		*email = "";
		*major = "";
		*level = "";
		*record = 0;
		*units = 0;
		return;
	}
	*record = stoi(line);
	getline(file, line, ',');
	*ID = stoi(line);
	getline(file, name1, ',');
	getline(file, name2, ',');
	name1 = name1 + ",";
	*name = name1 + name2;
	getline(file, *email, ',');
	getline(file, unit, ',');
	if (unit != "AU") {
		*units = stoi(unit);
	}
	else {
		*units = 555;
	}
	getline(file, *major, ',');
	getline(file, *level);
}

Data putRecord(string name, string email, string major, string level, int ID, int record, int units) {
	Data student;
	student.setRecordNum(record);
	student.setID(ID);
	student.setName(name);
	student.setEmail(email);
	student.setLevel(level);
	student.setMajor(major);
	student.setUnits(units);
	return student;
}
