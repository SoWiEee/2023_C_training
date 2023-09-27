/*
 * Prompt a user to input number of days in month and starting day of the week
 * Finally, print a one-month calendar like following
 *
 * Enter number of days in month:  31
 * Enter starting day of the week (1=Sun., 7=Sat.): 3
 *          1   2   3   4   5
 *  6   7   8   9  10  11  12
 * 13  14  15  16  17  18  19
 * 20  21  22  23  24  25  26
 * 27  28  29  30  31
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void scanDay(int*, int*);
void showCalendar(int, int);

int main(void) {
	int days, start;
	scanDay(&days, &start);
	showCalendar(days, start);


	system("PAUSE");
	return 0;
}

/*
 * Get and returns two integers from keyboard
 */
void scanDay(int* days, int* start) {
	int status_days, status_start;/*         status code returned by scanf indicating
								             number of valid values obtained                  */
	int error;                    /*         flag indicating presence of an error             */
	char discard;                 /*         unprocessed character from input line            */

	do {
		/* No errors detected yet                                                             */
		error = 0;

		/* Get number of days in month and starting day of the week from the user             */
		printf("Enter number of days in month: ");
		status_days = scanf("%d", days);
		printf("Enter starting day of the week (1= Sun., 7= Sat.): ");
		status_start = scanf("%d", start);

		/* Validate the fraction                                                              */
		if (status_days != 1 || status_start != 1) {
			error = 1;
			printf("Invalid\n");
		}
		else if (*days < 28 || *days > 31) {
			error = 1;
			printf("Invalid-number of days in month must between 28 and 31\n");
		}
		else if (*start < 1 || *start > 7) {
			error = 1;
			printf("Invalid-starting day of the week must between 1 and 7\n");
		}
		
		/* Discard extra input characters*/
		do {
			scanf("%c", &discard);
		} while (discard != '\n');
	} while (error);
}

/*
 * Get number of days in month and starting day of the week
 * show the Calendar
 */
void showCalendar(int days, int start) {
	int cur_week = 1; /* the day of week when output         */
	int i;        /* the loop control variable               */

	for (i = 1; i <= days; i++, cur_week++) {
		if (cur_week >= start) {
			printf("%2d  ", i);
		}
		else {
			i--;
			printf("    ");
		}

		if (cur_week % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}