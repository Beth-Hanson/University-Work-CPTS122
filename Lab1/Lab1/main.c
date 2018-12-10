/* Programmer: Elisabeth (Beth) Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Lab 1
File: main.c
Date: 08/28/18
Description: */

#include "lab1.h"

int main() {
	//Task 2, 
	/*char strStuff[] = "Stuff";
	int j;
	j = strlen(strStuff) - 1;
	reverseStringRec(strStuff, 0, j);

	//2c
	//i
	char strA[] = "stuff";
	char strB[] = "more";
	char strC[] = "";
	strcpy(strC, strA);
	strcat(strC, strB);
	bubbleSort(strC, strlen(strC));

	//ii
	char stringA[] = "stuff";
	char stringB[] = "more";
	char stringC[10];
	*stringC = (char*)malloc(sizeof(char)*(strlen(stringA) + strlen(stringB)));
	strcpy(stringC, stringA);
	strcat(stringC, stringB);
	bubbleSort(stringC, strlen(stringC));
	free(stringC);*/

	//iii

	//2d
	FILE *infile = NULL;
	infile = fopen("infile.txt", "r");
	char line[128] = "";
	int charAr[128] = { 0 };
	int i = 0;
	while (!feof(infile)) {
		fgets(line, 128, infile);
		while (line[i] != '\0') {
			charAr[line[i]]++;
			i++;
		}
	}

	system("pause");
	return;
}