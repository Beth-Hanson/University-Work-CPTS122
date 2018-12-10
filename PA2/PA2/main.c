/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 2
File: main.c
Date: 09/07/18
Description: */

#include "playlist.h"

int main() {
	int response = 0, inputOkay = 0, minute = 0, second = 0, count = 0;
	int menuChoice = 0;
	FILE *infile = NULL;
	Node *pHead = NULL;
	//Node **pStart = NULL; //Sentinel Node for if I can figure out Circular Linked list
	Record userInput;
	Record song;
	char fileLine[100];
	char token = '\"';
	char trash; //to clear buffer
	char *pLine = NULL;
	char *pCharPosition = NULL;
	char author[100];

	srand((unsigned int)time(NULL));


	do { //Menu, switch case, and do/while loops from my 121 final
		do {
			printf("\n Please Select from the Following Menu\n");
			printf("1) Load\n");
			printf("2) Store\n");
			printf("3) Display\n");
			printf("4) Insert\n");
			printf("5) Delete\n");
			printf("6) Edit\n");
			printf("7) Sort\n");
			printf("8) Rate\n");
			printf("9) Play\n");
			printf("10) Shuffle\n");
			printf("11) Exit\n");
			printf(">> ");
			scanf("%d", &response);
		} while (response < 1 || response > 11);
		printf("\n");
		system("cls");
		switch (response) {
		case 1: 
			//Load
			infile = openFile(infile, "musicPlayList.csv", "r", &inputOkay);
			while (!feof(infile)) {
				fgets(fileLine, 100, infile);
				pCharPosition = strchr(fileLine, '\n');
				if (pCharPosition != NULL) {
					strtok(fileLine, "\n");
				}
				pCharPosition = strchr(fileLine, token);
				if (pCharPosition != NULL) {
					pLine = strtok(pCharPosition, ",");
					strcpy(author, pLine);
					pCharPosition = strchr(author, token);
					if (pCharPosition != NULL) {
						pLine = strtok(NULL, ",");
						char *justWork = ",";
						strcat(author, justWork);
						strcat(author, pLine);
					}
				}
				else {
					pLine = strtok(fileLine, ",");
					strcpy(author, fileLine);
				}
				strcpy(song.artist, author);
				pLine = strtok(NULL, ",");
				strcpy(song.albumTitle, pLine);
				pLine = strtok(NULL, ",");
				strcpy(song.songTitle, pLine);
				pLine = strtok(NULL, ",");
				strcpy(song.genre, pLine);
				pLine = strtok(NULL, ",");
				sscanf(pLine, "%d%c%d", &minute, &trash, &second);
				song.songLength.minutes = minute;
				song.songLength.seconds = second;
				pLine = strtok(NULL, ",");
				song.playTime = atoi(pLine);
				pLine = strtok(NULL, ",");
				song.rating = atoi(pLine);
				inputOkay = insertAtFront(&pHead, song);
				if (inputOkay != 0) {
					count++;
				}
			}
			fclose(infile);
			break;
		case 2: 
			//Store
			infile = openFile(infile, "musicPlayList.csv", "w", &inputOkay);
			filePrintList(pHead, infile);
			fclose(infile);
			break;
		case 3: 
			//Display
			printList(pHead);
			break;
		case 4: 
			//Insert
			inputOkay = 0;
			while (inputOkay == 0) {
				printf("Enter Artist Name for New Record:\n");
				gets(userInput.artist);
				gets(userInput.artist);
				printf("Enter Album Title for New Record:\n");
				gets(userInput.albumTitle);
				printf("Enter Genre for New Record:\n");
				gets(userInput.genre);
				printf("Enter Song Title for New Record:\n");
				gets(userInput.songTitle);
				printf("Enter Song Length for New Record:\n");
				scanf("%d%c%d", &userInput.songLength.minutes, &trash, &userInput.songLength.seconds);
				printf("Enter Rating for New Record:\n");
				scanf("%d", &userInput.rating);
				printf("Enter Number of times played for New Record:\n");
				scanf("%d", &userInput.playTime);
				inputOkay = insertData(pHead, userInput);
			}
			if (inputOkay != 0) {
				count++;
			}
			break;
		case 5: 
			//Delete
			inputOkay = 0;
			printf("Enter Song Title for Record to be Deleted:\n");
			gets(userInput.songTitle);
			gets(userInput.songTitle);
			printList(pHead);
			inputOkay = deleteItem(&pHead, userInput);
			if (inputOkay != 0) {
				count--;
			}
			break;
		case 6: 
			//Edit
			editNode(&pHead);
			break;
		case 7: 
			//Sort
			printf("Select How You would like to sort:\n"
				"1. Sort based on artist (A-Z)\n"
				"2. Sort based on album title (A-Z)\n"
				"3. Sort based on rating (1 - 5)\n"
				"4. Sort based on times played (largest - smallest)\n");
			scanf("%d", &menuChoice);
			switch (menuChoice) {
			case 1:
				//based on artist
				bubbleSortArtist(pHead);
				break;
			case 2:
				//album
				bubbleSortAlbum(pHead);
				break;
			case 3:
				//rating
				bubbleSortRating(pHead);
				break;
			case 4:
				//times played
				bubbleSortPlayTime(pHead);
				break;
			}
			break;
		case 8: 
			//Rate
			rateSong(&pHead);
			break;
		case 9:
			//Play
			while (pHead != NULL)
			{
				printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pHead->musicData.artist, pHead->musicData.albumTitle,
					pHead->musicData.songTitle, pHead->musicData.genre, pHead->musicData.songLength.minutes,
					pHead->musicData.songLength.seconds, pHead->musicData.playTime, pHead->musicData.rating);
				Sleep(5000);
				system("cls");
				pHead = pHead->pNext;
			}
			break;
		case 10:
			//Shuffle
			printList(pHead);
			shuffle(&pHead, count);
			printList(pHead);
			system("pause");
			break;
		case 11:
			//Exit
			infile = openFile(infile, "musicPlayList.csv", "w", &inputOkay);
			filePrintList(pHead, infile);
			fclose(infile);
			response = 12;
			break;
		}
	} while (response != 12);

	return;
}