/* Programmer: Elisabeth (Beth) Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Lab 2
File: lab2.c
Date: 09/04/18
Description: */

#include "lab2.h"

Node *makeNode(Contact newData) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	memcpy(&newNode->data, &newData, sizeof(Contact));
	return newNode;
}

Boolean insertContactInOrder(Node **pList, Contact newData) {
	Boolean success = FALSE;
	Node *newNode = NULL, *pCur = *pList, *pPrev = NULL;
	newNode = makeNode(newData);

	if (newNode != NULL) {
		success = TRUE;
		if (*pList == NULL) {
			*pList = newNode;
		}
		else {
			while ((pCur != NULL) && (newNode->data.name > pCur->data.name)) {
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			if (pPrev != NULL) {
				newNode->pNext = pCur;
				pPrev->pNext = newNode;
			}
			else {
				newNode->pNext = pCur;
				*pList = newNode;
			}

		}
	}

	return success;
}

Boolean deleteContact(Node **pList, Contact searchContact) {
	Boolean success = FALSE;
	Node *pMem = *pList, *pPrev = NULL, *pCur = *pList;
	while (pMem != NULL) {
		pPrev = pCur;
		pCur = pCur->pNext;
		if (pMem->data.name == searchContact.name) {
			success = TRUE;
			free(pMem);
			pMem = pCur;
		}

	}

	return success;
}

Boolean editContact(Node *pList, Contact searchContact) {
	Boolean success = FALSE;


	return success;
}