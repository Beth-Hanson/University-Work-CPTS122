#include "test.h"

void testInsert() {
	Record test;
	Node *pTest = NULL;
	int inputOkay = 0;
	strcpy(test.artist, "\"Perry, Katy\"");
	strcpy(test.albumTitle, "Witness");
	strcpy(test.songTitle, "Chained to the Rhythm");
	strcpy(test.genre, "pop");
	test.songLength.minutes = 4;
	test.songLength.seconds = 36;
	test.playTime = -1;
	test.rating = 6;
	inputOkay = insertData(pTest, test);
	if (inputOkay == 1) {
		printf("Data Inserted Correctly");
	}
	if (inputOkay == 0) {
		printf("Data failed to insert");
	}
	if (inputOkay == -1) {
		printf("Invalid rating");
	}
	if (inputOkay == -2) {
		printf("Invalid number of times played");
	}

}

void testDelete() {
	Record test;
	Node *pTest = NULL;
	int inputOkay = 0;
	strcpy(test.artist, "\"Perry, Katy\"");
	strcpy(test.albumTitle, "Witness");
	strcpy(test.songTitle, "Chained to the Rhythm");
	strcpy(test.genre, "pop");
	test.songLength.minutes = 4;
	test.songLength.seconds = 36;
	test.playTime = -1;
	test.rating = 6;
	inputOkay = insertAtFront(&pTest, test);
	if (inputOkay == 0) {
		printf("Failed to allocate memory");
	}
	inputOkay = deleteItem(&pTest, test);
	if (inputOkay == 0) {
		printf("Failed to delete Node");
	}

}

void testShuffle() {
	Record test;
	Node *pTest = NULL;
	int inputOkay = 0, count = 3;
	strcpy(test.artist, "3");
	strcpy(test.albumTitle, "3");
	strcpy(test.songTitle, "3");
	strcpy(test.genre, "3");
	test.songLength.minutes = 3;
	test.songLength.seconds = 3;
	test.playTime = 3;
	test.rating = 3;
	inputOkay = insertAtFront(&pTest, test);

	strcpy(test.artist, "2");
	strcpy(test.albumTitle, "2");
	strcpy(test.songTitle, "2");
	strcpy(test.genre, "2");
	test.songLength.minutes = 2;
	test.songLength.seconds = 2;
	test.playTime = 2;
	test.rating = 2;
	inputOkay = insertAtFront(&pTest, test);

	strcpy(test.artist, "1");
	strcpy(test.albumTitle, "1");
	strcpy(test.songTitle, "1");
	strcpy(test.genre, "1");
	test.songLength.minutes = 1;
	test.songLength.seconds = 1;
	test.playTime = 1;
	test.rating = 1;
	inputOkay = insertAtFront(&pTest, test);
	shuffle(&pTest, count);
}