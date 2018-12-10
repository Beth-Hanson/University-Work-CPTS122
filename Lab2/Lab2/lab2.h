/* Programmer: Elisabeth (Beth) Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Lab 2
File: lab2.h
Date: 09/04/18
Description: */

#ifndef LAB2_H
#pragma warning(disable: 4996)
#define LAB2_H

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct

typedef enum boolean {
	FALSE, TRUE
} Boolean;

typedef struct contact {
	char name[50];
	char phone[12];
	char email[50];
	char title[20];
} Contact;

typedef struct node {
	Contact data;
	struct node *pNext;
} Node;

//Functions
Node *makeNode(Contact newData);
Boolean insertContactInOrder(Node **pList, Contact newData);
Boolean deleteContact(Node **pList, Contact searchContact);
Boolean editContact(Node *pList, Contact searchContact);
Boolean loadContacts(FILE *infile, Node **pList);
Boolean storeContacts(FILE *infile, Node *pList);
void printList(Node *pList);

#endif