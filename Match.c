/*
 * Match.c
 *
 *  Created on: Feb 17, 2023
 *      Author: brinl
 */
#include <stdio.h>
//read from file and insert into arrays choices
int main() {
	//initializing arrays to hold the preferences for deparments and programmers. Departments are D and programmers are P
	int D1[5];
	int D2[5];
	int D3[5];
	int D4[5];
	int D5[5];
	int P[5][5];
	FILE *preferences;
	//open the file for reading
	preferences = fopen("matching-data.txt", "r");
	//check if the file was opened successfully
	if (preferences == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	//read the preference data from the file
	for (int j = 0; j < 10; j++) {
		if (j < 5) {
			for (int i = 0; i < 5; i++) {
				//assign the first five rows to the departments (the first column corresponds to the first department etc)
				switch (i) {
					case 0:
						fscanf(preferences, "%d", &D1[j]);
						break;
					case 1:
						fscanf(preferences, "%d", &D2[j]);
						break;
					case 2:
						fscanf(preferences, "%d", &D3[j]);
						break;
					case 3:
						fscanf(preferences, "%d", &D4[j]);
						break;
					case 4:
						fscanf(preferences, "%d", &D5[j]);
						break;
				}
			}
		} else {
			for (int i = 0; i < 5; i++) {
				//assign the second five rows to the programmers
				fscanf(preferences, "%d", &P[i][j-5]);
			}
		}
	}
	//close the file
	fclose(preferences);

	//initialize the programmers assigned to each department to their first choices
	int choiceD1 = 0;
	int choiceD2 = 0;
	int choiceD3 = 0;
	int choiceD4 = 0;
	int choiceD5 = 0;
	int D_P[5] = {D1[choiceD1], D2[choiceD2], D3[choiceD3], D4[choiceD4], D5[choiceD5]};


	//check the department preferences
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			//iterate through the department assignments and compare them to each other to see if they have the same one
			if (D_P[i] == D_P[j] && i != j) {
				for (int k = 0; k < 5; k++) {
					if (P[D_P[i]-1][k] == i+1) { //if the programmer has the preference of the i department first
						//a switch to see which department we're dealing with; make the j department have its next choice
						switch (j) {
						case 0:
							D_P[j] = D1[++choiceD1];
							break;
						case 1:
							D_P[j] = D2[++choiceD2];
							break;
						case 2:
							D_P[j] = D3[++choiceD3];
							break;
						case 3:
							D_P[j] = D4[++choiceD4];
							break;
						case 4:
							D_P[j] = D5[++choiceD5];
							break;
						}
						break;
					} else if (P[D_P[j]-1][k] == j+1) { //if the programmer has the preference of the j department first
						//a switch to see which department we're dealing with; make the i department have its next choice
						switch (i) {
							case 0:
								D_P[i] = D1[++choiceD1];
							case 1:
								D_P[i] = D2[++choiceD2];
								break;
							case 2:
								D_P[i] = D3[++choiceD3];
								break;
							case 3:
								D_P[i] = D4[++choiceD4];
								break;
							case 4:
								D_P[i] = D5[++choiceD5];
								break;
						}
						break;
					}
				}
			}
		}
	}

	//print out the output
	printf("Department #1 will get Programmer #%d\n", D_P[0]);
	printf("Department #2 will get Programmer #%d\n", D_P[1]);
	printf("Department #3 will get Programmer #%d\n", D_P[2]);
	printf("Department #4 will get Programmer #%d\n", D_P[3]);
	printf("Department #5 will get Programmer #%d\n", D_P[4]);
}
