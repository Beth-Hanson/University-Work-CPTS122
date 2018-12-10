#include "test.h"

int testIsEmpty(Stack pStack) {
	int success = 0;
	success = isEmpty(pStack);
	return success;
}

int testPush(Stack *pStack) {
	int success = 0;
	success = push(pStack, 18.5);
	if (pStack->pTop->data == 18.5) {
		success = 1;
	}
	else {
		success = 0;
	}
	return success;
}

int testPop(Stack *pStack) {
	int success = 0;
	Node *pTemp = pStack->pTop->pNext;
	pop(pStack);
	if (pStack->pTop == pTemp) {
		success = 1;
	}
	return success;
}

int testTop(Stack *pStack) {
	int success = 0;
	double result = top(pStack);
	if (result == pStack->pTop->data) {
		success = 1;
	}
	return success;
}