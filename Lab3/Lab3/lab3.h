#ifndef LAB3_H
#pragma warning(disable: 4996)
#define LAB3_H
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//enums, structs, nodes
typedef struct node {
	double data;
	struct node *pNext;
} Node;

typedef struct stack {
	Node *pTop;
} Stack;

//Functions
int isEmpty(Stack stack);
Node *makeNode(double newData);
int push(Stack *pStack, double newData);
void pop(Stack *pStack);
double top(Stack *pStack);

#endif
