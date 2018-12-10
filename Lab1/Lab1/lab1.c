/* Programmer: Elisabeth (Beth) Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Lab 1
File: lab1.c
Date: 08/28/18
Description: */

#include "lab1.h"
//Task 1, a
//Function recommended, as seen below, causes stack overflow. 
/*void reverseStringRec(char *str, int n) {
	if (str[n] != '\0') {
		char temp = str[n];
		reverseStringRec(str, n++);
		str[strlen(str) - 1 - n] = temp;
	}
	else if (str[n] == '\0') {
		return;
	}
	
} */

//Function reverses a string through recursion. i is the start, j is the end variable. 
void reverseStringRec(char str[], int i, int j) {
	if (i > j) {
		return;
	}
	else {
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		reverseStringRec(str, i + 1, j - 1);
	}
}

//2c
//Couldn't get bubble sort to work. Sort given was incorrect. If I had more time, I would have fixed it. 
void bubbleSort(char str[], int n) {
	int i = 0, j = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (str[j] > str[i]) {
				char temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;

			}
		}
	}
}