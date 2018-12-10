/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 2
File: playlist.h
Date: 09/07/18
Description: */

#ifndef PLAYLIST_H
#pragma warning(disable: 4996)
#define PLAYLIST_H

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


//Structs and Enums
typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {
	char artist[100];
	char albumTitle[100]; 
	char songTitle[100];
	char genre[100];
	Duration songLength;
	int playTime;
	int rating;
} Record;

typedef struct node {
	struct node *pPrev;
	Record musicData;
	struct node *pNext;
} Node;

//Functions
FILE * openFile(FILE *file, const char *fileName, const char *mode, int *pOkay);
int fileCheck(FILE *file);
Node *makeNode(Record newItem);
int insertAtFront(Node **pList, Record newItem);
void printList(Node *pList);
void filePrintList(Node *pList, FILE *file);
void rateSong(Node **pList);
void editNode(Node **pList);
void swapRecord(Node *pA, Node *pB);
void bubbleSortArtist(Node *pList);
void bubbleSortAlbum(Node *pList);
void theDoubleQuoteProblemArtist(Node *pList);
void bubbleSortRating(Node *pList);
void bubbleSortPlayTime(Node *pList);
int deleteItem(Node **pList, Record target);
int insertData(Node *pList, Record userInput);
void shuffle(Node **pList, int count);

#endif