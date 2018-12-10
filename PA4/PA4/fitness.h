/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 4
File: fitness.h
Date: 10/07/18
Description: */

#pragma once
#pragma warning(disable: 4996)
//Libraries
#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

//Classes
class DietPlan {
public:
	DietPlan(int newGoal = 0, string newName = "", string newDate = "");
	DietPlan(DietPlan &copy);
	~DietPlan();
	//Getters
	int getGoalCal();
	string getName();
	string getDate();
	//Setters
	void setGoalCal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();

private:
	int mGoalCal;
	string mName;
	string mDate;

};

class ExercisePlan {
public:
	ExercisePlan();
	ExercisePlan(ExercisePlan &copy);
	~ExercisePlan();
	//Getters
	int getGoalSteps();
	string getName();
	string getDate();
	//Setters
	void setGoalSteps(int newGoal);
	void setName(string newName);
	void setDate(string newDate);

	void editGoal();

private:
	int mGoalSteps;
	string mName;
	string mDate;

};

class FitnessAppWrapper {
public:
	void runApp();
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(DietPlan &plan);
	void displayDailyPlan(ExercisePlan &plan);
	void displayWeeklyPlan(DietPlan plan[]);
	void displayWeeklyPlan(ExercisePlan plan[]);
	void storeDailyPlan(fstream &fileStream, DietPlan plan);
	void storeDailyPlan(fstream &fileStream, ExercisePlan plan);
	void storeWeeklyPlan(fstream &fileStream, DietPlan plan[]);
	void storeWeeklyPlan(fstream &fileStream, ExercisePlan plan[]);
	int displayMenu();

private:
	ExercisePlan mEWeeklyPlan[7];
	DietPlan mDWeeklyPlan[7];
	fstream infile;
	fstream outfile;
};

//nonmember functions
std::fstream & operator<< (std::fstream &lhs, DietPlan &rhs);
std::fstream & operator<< (std::fstream &lhs, ExercisePlan &rhs);
std::fstream & operator>> (std::fstream &lhs, DietPlan &rhs);
std::fstream & operator>> (std::fstream &lhs, ExercisePlan &rhs);