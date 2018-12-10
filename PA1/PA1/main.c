/*Programmer: Beth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 1
File: main.c
Date: 08/27/18
Description: To parse data from a file into a struct, and then printed
to another file along with other computations.*/

#include "fitbit.h"

int main() {

	//Local variable declarations
	FitbitData dataArray[1440];
	DataTotal resultTotal;
	FILE *infile = NULL, *outfile = NULL;
	char line[100] = "";
	char trash[100] = "";
	char targetPatient[100] = "";
	char *pString = NULL;
	char *pLine = NULL;
	int floorsSum = 0, heartRateSum = 0, stepsSum = 0, maxSteps = 0, sleepSum = 0, sleepMax = -1;
	double caloriesSum = 0, distanceSum = 0, aveHeartRate = 0;
	int inputOkay = 0, countForSize = 0, sleepOkay = 1, j = 0;
	
	//Opening files and checking for success
	infile = openFile(infile, "FitbitData.csv", "r", &inputOkay);
	outfile = openFile(outfile, "Results.csv", "w", &inputOkay);

	fgets(line, 1440, infile);
	sscanf(line, "%s %c %s", trash, trash, targetPatient); //taking only the target patient id
	strtok(targetPatient, ",,");
	fgets(trash, 1440, infile); // skipping the unnecessary line
	
	//Reading in lines from the file and parsing the data
	while (!feof(infile)) {
		fgets(line, 1440, infile);
		pLine = line;
		pLine = fixDoubleTokens(line, ',', "999");
		strcpy(line, pLine);
		for (int i = 0; i < 8; i++) {
			int arSpot = i;
			switch (arSpot) {
			case 0:
				pString = strtok(line, ",");
				char *pDupeCheck = NULL;
				pDupeCheck = strtok(NULL, ",");
				inputOkay = checkDupe(pDupeCheck, dataArray, countForSize);
				if ((strcmp(pString, targetPatient) != 0)|| (inputOkay != 0)) {
					countForSize -= 1;
					i = 8;
					break;
				}
				else {
					strcpy(dataArray[countForSize].patient, pString);
				}
				break;
			case 1:
				pString = pDupeCheck;
				strcpy(dataArray[countForSize].minute, pString);
				break;
			case 2:
				pString = strtok(NULL, ",");
				dataArray[countForSize].calories = atof(pString);
				break;
			case 3:
				pString = strtok(NULL, ",");
				dataArray[countForSize].distance = atof(pString);
				break;
			case 4:
				pString = strtok(NULL, ",");
				dataArray[countForSize].floors = atoi(pString);
				break;
			case 5:
				pString = strtok(NULL, ",");
				dataArray[countForSize].heartRate = atoi(pString);
				break;
			case 6:
				pString = strtok(NULL, ",");
				dataArray[countForSize].steps = atoi(pString);
				break;
			case 7:
				pString = strtok(NULL, ",");
				dataArray[countForSize].sleepLevel = atoi(pString);
				break;
			}
		}
		countForSize++;
	}
	
	//Calculating sums and maximums
	for (int i = 0; i < countForSize; i++) {
		if (dataArray[i].calories < 999) {
			caloriesSum += dataArray[i].calories;

		}
		if (dataArray[i].distance < 999) {
			distanceSum += dataArray[i].distance;

		}
		if (dataArray[i].floors < 999) {
			floorsSum += dataArray[i].floors;

		}
		if (dataArray[i].heartRate < 999) {
			heartRateSum += dataArray[i].heartRate;

		}
		if (dataArray[i].steps < 999) {
			stepsSum += dataArray[i].steps;
			if (dataArray[i].steps > maxSteps) {
				maxSteps = dataArray[i].steps;
			}
		}
		if ((dataArray[i].sleepLevel > ASLEEP) && (sleepOkay != 0)) {
			strcpy(resultTotal.minuteStart, dataArray[i].minute);
			j = i;
			while (dataArray[j].sleepLevel > ASLEEP) {
				sleepSum += dataArray[j].sleepLevel;
				j++;
			}
			sleepOkay = 0;
		}
		if (sleepSum > sleepMax) {
			sleepMax = sleepSum;
			strcpy(resultTotal.minuteEnd, dataArray[j].minute);
			sleepOkay = 1;
		}
		if (resultTotal.minuteEnd == "\0") {
			strcpy(resultTotal.minuteStart, "\0");
			sleepOkay = 1;
		}
		
	}

	aveHeartRate = aveData(heartRateSum, countForSize);
	
	//printing to outfile
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s:%s\n", caloriesSum, distanceSum, floorsSum, stepsSum, aveHeartRate, maxSteps, resultTotal.minuteStart, resultTotal.minuteEnd);
	for (int i = 0; i < countForSize; i++) {
		fprintf(outfile, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", dataArray[i].patient, dataArray[i].minute, dataArray[i].calories, dataArray[i].distance, dataArray[i].floors, dataArray[i].heartRate, dataArray[i].steps, dataArray[i].sleepLevel);
	}
	

	fclose(infile);
	fclose(outfile);

	return;
}