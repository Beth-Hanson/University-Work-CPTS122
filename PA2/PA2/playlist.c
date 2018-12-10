/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 2
File: playlist.c
Date: 09/07/18
Description: */

#include "playlist.h"

/*
Function: openFile()
Description: opens the file and checks for success in opening the file by means of the fileCheck function
Input parameters: a file pointer, the file name, and the mode for opening
*/
FILE * openFile(FILE *file, const char *fileName, const char *mode, int *pOkay) {
	file = fopen(fileName, mode);
	*pOkay = fileCheck(file);
	return file;
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
Function: makeNode()
Description: Makes a Node
Input parameters: Record data
Returns: node
*/
Node *makeNode(Record newItem) {
	Node *pMem = NULL;
	pMem = (Node *)malloc(sizeof(Node));
	pMem->musicData = newItem;
	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}

/*
Function: insertAtFront()
Description: inserts new node at front of list.
Input parameters: a pointer to a node, record data
Returns: int
*/
int insertAtFront(Node **pList, Record newItem) {
	int success = 0;
	Node *pMem = NULL;

	pMem = makeNode(newItem);

	if (pMem != NULL) {
		success = 1;
		pMem->pNext = *pList;
		if (*pList != NULL) {
			(*pList)->pPrev = pMem;
		}
		*pList = pMem;
	}

	return success;
}

/*
Function: editNode()
Description: edits data in Node
Input parameters: a node pointer
Returns: 
*/
void editNode(Node **pList) {
	Record tempRecord;
	Node *pTemp = NULL;
	char *check = NULL;
	char artist[50], song[100];
	char temp[20];
	printf("Enter Artist to Search Exactly as displayed in list, If No Second Name indicate with a space and N/A: \n");
	gets(artist);
	gets(artist);
	/*check = strchr(artist, ',');
	if (check != NULL) {
		strcat(artist, " ");
		strcat(artist, temp);
	}*/
	printf("All Records from this Artist displayed below\n");
	while ((*pList)->pNext != NULL) {
		if (strcmp((*pList)->musicData.artist, artist) == 0) {
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", (*pList)->musicData.artist, (*pList)->musicData.albumTitle,
				(*pList)->musicData.songTitle, (*pList)->musicData.genre, (*pList)->musicData.songLength.minutes,
				(*pList)->musicData.songLength.seconds, (*pList)->musicData.playTime, (*pList)->musicData.rating);
		}
		*pList = (*pList)->pNext;
	}
	printf("Enter the Song Title of the file you wish to edit. \n");
	gets(song);
	//gets(song);
	system("cls");
	if ((*pList)->pNext == NULL) {
		*pList = (*pList)->pPrev;
		while ((*pList)->pPrev != NULL) {
			if (strcmp((*pList)->musicData.songTitle, song) == 0) {
				printf("Enter Artist Name for record \n");
				gets(tempRecord.artist);
				printf("Enter Album Name\n");
				gets(tempRecord.albumTitle);
				printf("Enter Song Name\n");
				gets(tempRecord.songTitle);
				printf("Enter Genre\n");
				gets(tempRecord.genre);
				printf("Enter Song length in minutes : seconds\n");
				scanf("%d %d", &tempRecord.songLength.minutes, &tempRecord.songLength.seconds);
				printf("Enter Number of times to Play song\n");
				scanf("%d", &tempRecord.playTime);
				printf("Enter Rating for Song 1 - 5 \n");
				scanf("%d", &tempRecord.rating);
				(*pList)->musicData = tempRecord;
			}
			*pList = (*pList)->pPrev;
		}
	}

}

/*
Function: rateSong()
Description: changes rating in record in node
Input parameters: a node pointer
Returns: 
*/
void rateSong(Node **pList) {
	char songTitle[50];
	int rating = 0;
	printf("Enter Song Title to rate exactly as it appears in the file:\n");
	gets(songTitle);
	gets(songTitle);
	strtok(songTitle, "\n");
	while (*pList != NULL) {
		if (strcmp((*pList)->musicData.songTitle, songTitle) == 0) {
			printf("Enter Rating for Song 1 - 5 \n");
			scanf("%d", &rating);
			(*pList)->musicData.rating = rating;
		}
		*pList = (*pList)->pNext;
	}
}

//Coming back to if I ever figure out circular lists
/*int insertinCir(Node **pList, Record newItem) {
	int success = 0;
	Node *pMem = NULL;

	pMem = makeNode(newItem);

	if (pMem != NULL) {
		success = 1;
		if (*pList == NULL) {
			pMem->pNext = pMem;
			pMem->pPrev = pMem;
		}
		
		if (*pList != NULL) {
			(*pList)->pPrev = pMem;
			pMem->pNext = *pList;
			pMem->pPrev = *pList;
		}
		
		*pList = pMem;
	}

	return success;
}*/

/*
Function: printList()
Description: prints list
Input parameters: Node
Returns: 
*/
void printList(Node *pList) {
	int option = 0;
	char artist[50], temp[20];
	char *check = NULL;
	printf("Choose from the following: \n"
		"1. Print all records\n"
		"2. Print all records that match an artist\n");
	scanf("%d", &option);
	system("cls");
	if (option == 1) {
		while (pList != NULL)
		{
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pList->musicData.artist, pList->musicData.albumTitle,
				pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
				pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
			pList = pList->pNext;
		}
	}
	if (option == 2) {
		printf("Enter Artist to Search Exactly as displayed in list, If No Second Name indicate with a space and N/A: \n");
		gets(artist);
		gets(artist);
		/*check = strchr(artist, ',');
		if (check != NULL) {
			strcat(artist, " ");
			strcat(artist, temp);

		}*/

		while (pList != NULL) {
			if (strcmp(pList->musicData.artist, artist) == 0) {
				printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pList->musicData.artist, pList->musicData.albumTitle,
					pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
					pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
			}
			pList = pList->pNext;
		}
		
		system("pause");
	}

}

//If I ever figure out circular lists
/*void printListCirc(Node *pList) {
	int option = 0;
	char artist[50], temp[20];
	char *check = NULL;
	printf("Choose from the following: \n"
		"1. Print all records\n"
		"2. Print all records that match an artist\n");
	scanf("%d", &option);
	if (option == 1) {
		while (pList != NULL)
		{
			printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pList->musicData.artist, pList->musicData.albumTitle,
				pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
				pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
			pList = pList->pNext;
		}
	}
	if (option == 2) {
		printf("Enter Artist to Search Exactly as displayed in list: \n");
		scanf("%s%s", artist, temp);
		check = strchr(artist, ',');
		if (check != NULL) {
			strcat(artist, " ");
		}
		strcat(artist, temp);
		printf("%s", artist);
		system("pause");
	}
	
}*/

//If I ever figure out circular lists
/*void filePrintListCirc(Node *pList, Node **pStart, FILE *file) {
	while (pList != *pStart)
	{
		fprintf(file, "%s,%s,%s,%s,%d:%d,%d,%d\n", pList->musicData.artist, pList->musicData.albumTitle,
			pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
			pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
		pList = pList->pNext;
	}
	if (pList == *pStart) {
		fprintf(file, "%s,%s,%s,%s,%d:%d,%d,%d\n", pList->musicData.artist, pList->musicData.albumTitle,
			pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
			pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
	}
}*/

/*
Function: filePrintList()
Description: prints list to file
Input parameters: a file pointer, a node
Returns: 
*/
void filePrintList(Node *pList, FILE *file) {
	while (pList->pNext != NULL) {
		fprintf(file, "%s,%s,%s,%s,%d:%d,%d,%d\n", pList->musicData.artist, pList->musicData.albumTitle,
			pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
			pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
		pList = pList->pNext;
	}
	if (pList->pNext == NULL) {
		fprintf(file, "%s,%s,%s,%s,%d:%d,%d,%d ", pList->musicData.artist, pList->musicData.albumTitle,
			pList->musicData.songTitle, pList->musicData.genre, pList->musicData.songLength.minutes,
			pList->musicData.songLength.seconds, pList->musicData.playTime, pList->musicData.rating);
	}
}

void swapRecord(Node *pA, Node *pB) {
	Record temp;
	temp = pA->musicData;
	pA->musicData = pB->musicData;
	pB->musicData = temp;
}

void bubbleSortArtist(Node *pList) {
	int swapped = 0, i = 0;
	Node *pTemp;
	Node *pPrev = NULL;
	if (pList == NULL) {
		return;
	}
	do {
		swapped = 0;
		pTemp = pList;
		while (pTemp->pNext != pPrev) {
			theDoubleQuoteProblemArtist(pTemp);
			if(strcmp(pTemp->musicData.artist, pTemp->pNext->musicData.artist) > 0) {
				swapRecord(pTemp, pTemp->pNext);
				swapped = 1;
			}
			pTemp = pTemp->pNext;
		}
		pPrev = pTemp;
	} while (swapped);
}

void theDoubleQuoteProblemArtist(Node *pList) {
	char temp[100];
	char *pTemp;
	char token = '\"';
	if (!strchr(pList->musicData.artist, token)) {
		pTemp = pList->musicData.artist;
		strcpy(temp, "\"");
		strcat(temp, pTemp);
		strcat(temp, "\"");
		strcpy(pList->musicData.artist, temp);
	}
}

void bubbleSortAlbum(Node *pList) {
	int swapped = 0, i = 0;
	Node *pTemp;
	Node *pPrev = NULL;
	if (pList == NULL) {
		return;
	}
	do {
		swapped = 0;
		pTemp = pList;
		while (pTemp->pNext != pPrev) {
			if (strcmp(pTemp->musicData.albumTitle, pTemp->pNext->musicData.albumTitle) > 0) {
				swapRecord(pTemp, pTemp->pNext);
				swapped = 1;
			}
			pTemp = pTemp->pNext;
		}
		pPrev = pTemp;
	} while (swapped);
}

void bubbleSortRating(Node *pList) {
	int swapped = 0, i = 0;
	Node *pTemp;
	Node *pPrev = NULL;
	if (pList == NULL) {
		return;
	}
	do {
		swapped = 0;
		pTemp = pList;
		while (pTemp->pNext != pPrev) {
			if (pTemp->musicData.rating < pTemp->pNext->musicData.rating) {
				swapRecord(pTemp, pTemp->pNext);
				swapped = 1;
			}
			pTemp = pTemp->pNext;
		}
		pPrev = pTemp;
	} while (swapped);
}

void bubbleSortPlayTime(Node *pList) {
	int swapped = 0, i = 0;
	Node *pTemp;
	Node *pPrev = NULL;
	if (pList == NULL) {
		return;
	}
	do {
		swapped = 0;
		pTemp = pList;
		while (pTemp->pNext != pPrev) {
			if (pTemp->musicData.playTime < pTemp->pNext->musicData.playTime) {
				swapRecord(pTemp, pTemp->pNext);
				swapped = 1;
			}
			pTemp = pTemp->pNext;
		}
		pPrev = pTemp;
	} while (swapped);
}

int deleteItem(Node **pList, Record target) {
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;

	while ((pCur != NULL) && (strcmp(pCur->musicData.songTitle, target.songTitle) != 0))
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL)
	{
		if (pPrev != NULL)
		{
			pPrev->pNext = pCur->pNext;
		}
		else
		{
			*pList = pCur->pNext;
		}
		success = 1;
		free(pCur);
	}

	return success;
}

int insertData(Node *pList, Record userInput) {
	int inputOkay = 0;
	if ((userInput.rating > 0 || userInput.rating < 5) && (userInput.playTime > 0)) {
		inputOkay = insertAtFront(&pList, userInput);
	}
	else {
		printf("Invalid Input\n");
		if (userInput.rating < 0 || userInput.rating > 5) {
			inputOkay = -1;
		}
		if (userInput.playTime < 0) {
			inputOkay = -2;
		}
	}

	return inputOkay;
}

void shuffle(Node **pList, int count) {
	int index = count, random, temp;
	Node *pCur = *pList;
	Record shuffleIt;
	int indexArr[100];
	for (int i = 0; i < count; i++) {
		indexArr[i] = i + 1;
	}

	for (int i = 0; i < count; i++){
		temp = indexArr[i];
		random = (rand() % (count - 1)) + 1;
		indexArr[i] = indexArr[random];
		indexArr[random] = temp;
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < indexArr[i]; j++) {
			if (pCur->pNext != NULL) {
				pCur = pCur->pNext;
			}
			shuffleIt = pCur->musicData;
		}
		printf("%s, %s, %s, %s, %d:%d, %d, %d\n", shuffleIt.artist, shuffleIt.albumTitle,
			shuffleIt.songTitle, shuffleIt.genre, shuffleIt.songLength.minutes,
			shuffleIt.songLength.seconds, shuffleIt.playTime, shuffleIt.rating);
		Sleep(5000);
		system("cls");
		while (pCur->pPrev != NULL) {
			pCur = pCur->pPrev;
		}
	}
}