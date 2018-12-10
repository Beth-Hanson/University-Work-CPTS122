/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 1
File: fitbit.h
Date: 08/27/18
Description: To parse data from a file into a struct, and then printed
to another file along with other computations.*/

#ifndef FITBIT_H
#pragma warning(disable: 4996)
#define FITBIT_H

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Structs and Enums
typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE =2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors; 
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

typedef struct total {
	char minuteStart[9];
	char minuteEnd[9];
} DataTotal;

//Functions
FILE * openFile(FILE * handle, const char * fileName, const char* mode, int *pOkay);
int fileCheck(FILE *file);
char *fixDoubleTokens(char line[], char token, char *insert);
int checkDupe(char *line, FitbitData data[], int n);
double aveData(double sum, int count);

#endif