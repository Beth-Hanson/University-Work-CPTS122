#include "lab3.h"

int isEmpty(Stack stack) {
	return (stack.pTop == NULL);
}

Node *makeNode(double newData) {
	Node *pMem = (Node *)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->data = newData;
		pMem->pNext = NULL;
	}
	return pMem;
}

int push(Stack *pStack, double newData) {
	Node *pMem = makeNode(newData);
	int success = 0;

	if (pMem != NULL) {
		success = 1;
		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}

void pop(Stack *pStack) {
	Node *pTemp = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;
	free(pTemp);
}

double top(Stack *pStack) {
	double returnData = pStack->pTop->data;
	return returnData;
}