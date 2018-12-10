#include "lab3.h"
#include "test.h"

int main() {
	Stack peg1 = { NULL }, peg2 = { NULL }, peg3 = { NULL };
	Stack stack = { NULL };
	int inputOkay = 0;
	inputOkay = testIsEmpty(stack);
	inputOkay = testPush(&stack);
	inputOkay = testTop(&stack);
	inputOkay = testPop(&stack);

	//Towers of Hanoi
	inputOkay = push(&peg1, 5);
	inputOkay = push(&peg1, 4);
	inputOkay = push(&peg1, 3);
	inputOkay = push(&peg1, 2);
	inputOkay = push(&peg1, 1);

	while (!(&peg1 == NULL && (&peg2 == NULL || &peg3 == NULL))) {
		if (top(&peg1) == 1 && &peg2 == NULL) {
			inputOkay = push(&peg3, top(&peg1));
			pop(&peg1);
			inputOkay = push(&peg2, top(&peg1));
			pop(&peg1);
		}
		if ((&peg1 != NULL || &peg2 != NULL || &peg3 != NULL)) {
			if (top(&peg3) < top(&peg2) && top(&peg2) < top(&peg1)) {
				inputOkay = push(&peg2, top(&peg3));
				pop(&peg3);
				inputOkay = push(&peg3, top(&peg1));
				pop(&peg1);
			}
			if (top(&peg2) < top(&peg1) && top(&peg2) < top(&peg3)) {
				inputOkay = push(&peg1, top(&peg2));
				pop(&peg2);
				inputOkay = push(&peg3, top(&peg2));
				pop(&peg2);
			}
		}
		
	}


	return;
}