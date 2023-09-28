#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

void showTimeTable(int startInt, int endInt);

int main(void)
{
	int startInt;	/* input - start integer of timetable	*/
	int endInt;		/* input - end integer of timetable		*/
	int status;		/* status value returned by scanf		*/
	int error;		/* flag indicating presence of an error */
	char discard;	/* unprocessd character from input line */

	/* Check user input two integer */
	do
	{
		/* no errors detected yet */
		error = 0;

		/* Hint user to input two integers for startInt and endInt */
		printf("Input start and end integers for time table(ex.6 9): ");
		status = scanf("%d %d", &startInt, &endInt);

		/* Check user input two integers are both less than 20 */
		if (status < 2)
		{
			error = 1;
			printf("Invalid - please input two integers.\n");
		}
		else if (startInt >= 20)
		{
			error = 1;
			printf("stratInt too large.\n");
		}
		else if (endInt >= 20)
		{
			error = 1;
			printf("endInt too large.\n");
		}
		else if (endInt < startInt)
		{
			error = 1;
			printf("startInt must be smaller than endInt.\n");
		}
		else
		{
			showTimeTable(startInt, endInt);
		}
		

		/* Discard extra input character */
		do
		{
			scanf("%c", &discard);
		} while (discard != '\n');

	} while (error);

	system("pause");
	return 0;
}

/*print timetable*/
void showTimeTable(int startInt,	/* input - start integer of timetable	*/
				   int endInt)		/* input - end integer of timetable		*/
{
	int label; /* local variable - indicate present printing */

	/* Use nest loop to print timetable */
	for (startInt; startInt <= endInt; startInt++)
	{
		for (label = startInt; label <= endInt; label++)
		{
			printf("%d X %d = %d\n", startInt, label, startInt*label);
		}
		printf("\n");
	}
}