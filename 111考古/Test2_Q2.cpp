/*
 * Prompt a user to input two positive integers less than 20, says startInt and endInt where startInt <= endInt
 * finally, print the time table on the console like following
 *
 * Input start and end integers for time table: 4 7
 * 
 * 4X4=16
 * 4X5=20
 * 4X6=24
 * 4X7=28
 *
 * 5X5=25
 * 5X6=30
 * 5X7=35
 * 
 * 6X6=36
 * 6X7=42
 *
 * 7X7=49
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void scanInt(int* startInt, int* endInt);
void showTimeTable(int, int);

int main(void) {
	int start, end;

	/* scan start and end integer*/
	scanInt(&start, &end);

	/* show the time table*/
	showTimeTable(start, end);

	system("PAUSE");
	return 0;
}

/* 
 * Get and returns two integers from keyboard
 */
void scanInt(int* startInt, int* endInt) {
	int status;      /*         status code returned by scanf indicating
								number of valid values obtained                  */
	int error;       /*         flag indicating presence of an error             */
	char discard;    /*         unprocessed character from input line            */

	do {
		/* No errors detected yet                                                */
		error = 0;

		/* Get two integers from the user                                        */
		printf("Input start and end integers for time table: ");
		status = scanf("%d %d", startInt, endInt);

		/* Validate the fraction                                                 */
		if (status != 2) {
			error = 1;
			printf("Invalid-please input two positive integers less than 20\n");
		}
		else if (*startInt <= 0 || *startInt >= 20) {
			error = 1;
			printf("Invalid-please input two positive integers less than 20\n");
		}
		else if (*endInt <= 0 || *endInt >= 20) {
			error = 1;
			printf("Invalid-please input two positive integers less than 20\n");
		}
		else if (*startInt > *endInt) {
			error = 1;
			printf("Invalid-start integer must less than or equal to end integer\n");
		}
		/* Discard extra input characters*/
		do {
			scanf("%c", &discard);
		} while (discard != '\n');
	} while (error);
}

/*
 * Get two integers
 * show the a time-table by sequentially listing all the possible cases of a x b,
 * where a <= b, startInt <= a, and b <= endInt
 */
void showTimeTable(int startInt, int endInt) {
	int i, j;       /* loop control variable */

	for (i = startInt; i <= endInt; i++) {
		printf("\n");
		for (j = i; j <= endInt; j++) {
			printf("%dX%d=%d\n", i, j, i * j);
		}
	}
}