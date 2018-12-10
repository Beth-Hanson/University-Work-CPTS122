/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 4
File: main.cpp
Date: 10/07/18
Description: */
#include "fitness.h"

//Constructor for DietPlan. Initializes class members
DietPlan::DietPlan(int newGoal, string newName, string newDate) {
	mGoalCal = newGoal;
	mName = newName;
	mDate = newDate;
}

//Copy Constructor for DietPlan. Copies data from one object to another
DietPlan::DietPlan(DietPlan &copy) {
	mGoalCal = copy.mGoalCal;
	mName = copy.mName;
	mDate = copy.mDate;
}

//Destructor for DietPlan. It was deallocate memory if there was memory to deallocate.
DietPlan::~DietPlan() {

}

//Getter for DietPlan member. Gets the GoalCal. 
int DietPlan::getGoalCal() {
	return mGoalCal;
}

//Getter for DietPlan member. Gets the Name. 
string DietPlan::getName() {
	return mName;
}

//Getter for DietPlan member. Gets the Date.
string DietPlan::getDate() {
	return mDate;
}

//Setter for DietPlan. Sets GoalCal to newGoal
void DietPlan::setGoalCal(int newGoal) {
	mGoalCal = newGoal;
}

//Setter for DietPlan. Sets Name to newName
void DietPlan::setName(string newName) {
	mName = newName;
}

//Setter for DietPlan. Sets Date to newDate
void DietPlan::setDate(string newDate) {
	mDate = newDate;
}

//Edits GoalCal to the user's input
void DietPlan::editGoal() {
	int newGoal = 0;
	cout << "Input New Calorie Goal" << endl;
	cin >> newGoal;
	setGoalCal(newGoal);
}

//Constructor for ExercisePlan. Initializes class members
ExercisePlan::ExercisePlan() {
	mGoalSteps = 0;
	mName = "";
	mDate = "";
}

//Copy Constructor for ExercisePlan. Copies data from one object to another
ExercisePlan::ExercisePlan(ExercisePlan &copy) {
	mGoalSteps = copy.mGoalSteps;
	mName = copy.mName;
	mDate = copy.mDate;
}

//Destructor for DietPlan. It was deallocate memory if there was memory to deallocate.
ExercisePlan::~ExercisePlan() {

}

//Getter for ExercisePlan. Gets GoalSteps
int ExercisePlan::getGoalSteps() {
	return mGoalSteps;
}

//Getter for ExercisePlan. Gets Name
string ExercisePlan::getName() {
	return mName;
}

//Getter for ExercisePlan. Gets Date
string ExercisePlan::getDate() {
	return mDate;
}

//Setter for ExercisePlan. Sets GoalSteps to newGoal
void ExercisePlan::setGoalSteps(int newGoal) {
	mGoalSteps = newGoal;
}

//Setter for ExercisePlan. Sets Name to newName
void ExercisePlan::setName(string newName) {
	mName = newName;
}

//Setter for ExercisePlan. Sets Date to newDate
void ExercisePlan::setDate(string newDate) {
	mDate = newDate;
}

//Edits GoalSteps to user's input
void ExercisePlan::editGoal() {
	int newGoal = 0;
	cout << "Input New Steps Goal" << endl;
	cin >> newGoal;
	setGoalSteps(newGoal);
}

//Operator overloader. Allows for outputting DietPlan object
std::fstream & operator<< (std::fstream &lhs, DietPlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalCal() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

//Operator overloader. Allows for outputting ExercisePlan object
std::fstream & operator<< (std::fstream &lhs, ExercisePlan &rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalSteps() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

//Operator overloader. Allows >> to take in data to a DietPlan object
std::fstream & operator>> (std::fstream &lhs, DietPlan &rhs) {
	int dataI = 0;
	string data;
	if (!lhs.eof()) {
		lhs >> data;
	}
	rhs.setName(data);
	if (!lhs.eof()) {
		lhs >> data;
	}
	dataI = stoi(data);
	rhs.setGoalCal(dataI);
	if (!lhs.eof()) {
		lhs >> data;
	}
	rhs.setDate(data);
	return lhs;
}

//Operator overloader. Allows >> to take in data to a ExercisePlan object
std::fstream & operator>> (std::fstream &lhs, ExercisePlan &rhs) {
	char data[100];
	int dataI = 0;
	if (!lhs.eof()) {
		lhs >> data;
	}
	string dataName(data);
	rhs.setName(dataName);
	if (!lhs.eof()) {
		lhs >> data;
	}
	dataI = atoi(data);
	rhs.setGoalSteps(dataI);
	if (!lhs.eof()) {
		lhs >> data;
	}
	string dataDate(data);
	rhs.setDate(dataDate);
	return lhs;
}

//Runs the App
void FitnessAppWrapper::runApp() {
	int response = 0, j = 0, i = 0;
	do {
		response = displayMenu();
		switch (response) {
		case 1:
			//load weekly diet
			infile.open("dietPlans.txt", std::fstream::in);
			loadWeeklyPlan(infile, mDWeeklyPlan);
			infile.close();
			break;
		case 2:
			//load weekly exercise
			infile.open("exercisePlans.txt", std::fstream::in);
			loadWeeklyPlan(infile, mEWeeklyPlan);
			infile.close();
			break;
		case 3:
			//store diet
			outfile.open("dietPlans.txt", std::fstream::out);
			storeWeeklyPlan(outfile, mDWeeklyPlan);
			outfile.close();
			break;
		case 4:
			//store exercise
			outfile.open("exercisePlans.txt", std::fstream::out);
			storeWeeklyPlan(outfile, mEWeeklyPlan);
			outfile.close();
			break;
		case 5:
			//display diet
			displayWeeklyPlan(mDWeeklyPlan);
			break;
		case 6:
			//display exercise
			displayWeeklyPlan(mEWeeklyPlan);
			break;
		case 7:
			//edit diet
			cout << "Select the name of the plan to be edit" << endl;
			cout << "1. Monday" << endl;
			cout << "2. Tuesday" << endl;
			cout << "3. Wednesday" << endl;
			cout << "4. Thursday" << endl;
			cout << "5. Friday" << endl;
			cout << "6. Saturday" << endl;
			cout << "7. Sunday" << endl;
			cin >> i;
			i = i - 1;
			mDWeeklyPlan[i].editGoal();
			break;
		case 8:
			//edit exercise
			cout << "Select the name of the plan to be edit" << endl;
			cout << "1. Monday" << endl;
			cout << "2. Tuesday" << endl;
			cout << "3. Wednesday" << endl;
			cout << "4. Thursday" << endl;
			cout << "5. Friday" << endl;
			cout << "6. Saturday" << endl;
			cout << "7. Sunday" << endl;
			cin >> j;
			j = j - 1;
			mEWeeklyPlan[j].editGoal();
			break;
		case 9:
			//exit
			outfile.open("dietPlans.txt", std::fstream::out);
			storeWeeklyPlan(outfile, mDWeeklyPlan);
			outfile.close();
			outfile.open("exercisePlans.txt", std::fstream::out);
			storeWeeklyPlan(outfile, mEWeeklyPlan);
			outfile.close();
			response = 10;
			break;
		}
		system("pause");
		system("cls");
	} while (response != 10);
}

//Reads plan from file
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

//reads plan from file
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;

}

//Uses load Daily plan and puts it into weekly array
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

//Uses load Daily plan and puts it into weekly array
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

//Displays Day Data
void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
	cout << plan.getName() << endl;
	cout << plan.getGoalCal() << endl;
	cout << plan.getDate() << endl;
}

//Displays Day Data
void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
	cout << plan.getName() << endl;
	cout << plan.getGoalSteps() << endl;
	cout << plan.getDate() << endl;
}

//Displays Weekly Data
void FitnessAppWrapper::displayWeeklyPlan(DietPlan plan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(plan[i]);
	}
}

//Displays Weekly Data
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan plan[]) {
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(plan[i]);
	}
}

//Writes daily plan to file
void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, DietPlan plan) {
	fileStream << plan << endl;
}

//writes daily plan to file
void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, ExercisePlan plan) {
	fileStream << plan << endl;
}

//Uses storeDailyPlan to write the week's plan to the file
void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, DietPlan plan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, plan[i]);
	}
}

//Uses storeDailyPlan to write the week's plan to the file
void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, ExercisePlan plan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fileStream, plan[i]);
	}
}

//Displays menu for the app
int FitnessAppWrapper::displayMenu() {
	int response = 0;
		cout << "1. Load weekly diet plan from file." << endl;
		cout << "2. Load weekly exercise plan from file." << endl;
		cout << "3. Store weekly diet plan to file." << endl;
		cout << "4. Store weekly exercise plan to file." << endl;
		cout << "5. Display weekly diet plan to screen." << endl;
		cout << "6. Display weekly exercise plan to screen." << endl;
		cout << "7. Edit daily diet plan." << endl;
		cout << "8. Edit daily exercise plan." << endl;
		cout << "9. Exit." << endl;
		cin >> response;
		return response;
}