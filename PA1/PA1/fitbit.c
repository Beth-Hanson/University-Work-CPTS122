/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 1
File: fitbit.c
Date: 08/27/18
Description: To parse data from a file into a struct, and then printed
to another file along with other computations.*/

#include "fitbit.h"

/*
Function: openFile()
Description: opens the file and checks for success in opening the file by means of the fileCheck function
Input parameters: a file pointer, the file name, and the mode for opening
*/
FILE * openFile(FILE * handle, const char * fileName, const char* mode, int *pOkay) {
	handle = fopen(fileName, mode);
	*pOkay = fileCheck(handle);
	return handle;
}

/*
Function: fileCheck()
Description: checks if the file pointer equals NULL and returns accordingly
Input parameters: a file pointer
Returns: an integer value
*/
int fileCheck(FILE *file) {
	if (file == NULL) {
		printf("File Failed to Open");
		return 0;
	}
	return 1;
}

/*
Function: fixDoubleTokens()
Description: takes a string and checks for a double token and inserts a value between the tokens
Input parameters: a string, a character, a string
Returns: a string
*/
char *fixDoubleTokens(char line[], char token, char *insert) {
	char *temp = NULL;
	for (int k = 0; line[k] != '\0'; k++) {
		if (line[k] == token && line[k - 1] == token) {
			temp = (char*)malloc(sizeof(char)*(strlen(line) + strlen(insert) + 1));
			int i = 0;
			for (; i < k; i++) {
				temp[i] = line[i];
			}
			int j = i;
			for (; j < strlen(insert) + i; j++) {
				temp[j] = insert[j - i];
			}
			temp[j] = '\0';
			strcat(temp, line + k);
			line = temp;
		}
		
	}
	return line;
}

/*
Function: checkDupe()
Description: checks for duplicate data and sets success accordingly
Input parameters: a string, struct data, an integer
Returns: an integer value
*/
int checkDupe(char *line, FitbitData data[], int n) {
	int success = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(line, data[i].minute) == 0) {
			success = 1;
			return success;
		}
	}
	return success;
}

/*
Function: aveData()
Description: takes the average of a double and an integer
Input parameters: a double, an integer
Returns: a double
*/
double aveData(double sum, int count) {
	double ave = 0;
	ave = sum / count;
	return ave;
}