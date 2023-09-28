#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

void printCalendar(int numberOfDays, int beginDay);

int main(void)
{
	/*Declare and initialize variables.*/
	int numberOfDays;	/* input - number of days in month			*/
	int beginDay;		/* input - starting day of the week			*/
	int status;			/* status returned by scanf					*/
	int error;			/* flag indicating presence of an error		*/
	char discard;		/* unprocessed character from input line	*/

	do
	{
		/* no errors detected yet */
		error = 0;

		/*Hint user to input number of days in month.*/
		printf("Enter number of days in month: ");
		status = scanf("%d", &numberOfDays);

		/* check user input an integer and reasonable days in month */
		if (status < 1)
		{
			error = 1;
			printf("Invalid - please input integer.\n");
		}
		else if (numberOfDays < 28 || numberOfDays > 31)
		{
			error = 1;
			printf("Invalid - Number of days in month should be from 28 to 31.\n");
		}

		/* discard extra input characters */
		do
		{
			scanf("%c", &discard);
		} while (discard != '\n');
	} while (error);

	do
	{
		/* no errors detected yet */
		error = 0;

		/*Hint user to input starting day of week.*/
		printf("Enter starting day of the week(1=Sun.,..., 7=Sat.): ");
		status = scanf("%d", &beginDay);

		/* check user input an integer and reasonable starting day of week */
		if (status < 1)
		{
			error = 1;
			printf("Invalid - please input integer.\n");
		}
		else if (beginDay < 1 || beginDay > 7)
		{
			error = 1;
			printf("Start day of the week shoule be from 1 to 7.\n");
		}

		/* discard extra input characters */
		do
		{
			scanf("%c", &discard);
		} while (discard != '\n');
	} while (error);

	printCalendar(numberOfDays, beginDay);

	system("pause");
	return(0);
}

/* Print calendar */
void printCalendar(int numberOfDays,	/* input - number of days in month			*/
				   int beginDays)		/* input - starting day of the week			*/
{
	int skipDays;		/*local variable - number of days before starting day					*/
	int countToSeven;	/*local variable - a counter to determine where should print next week	*/
	int day = 1;		/*local variable - day in month											*/

	/* Print "   " before starting day. */
	for (skipDays = 1; skipDays < beginDays; skipDays++)
	{
		printf("   ");
	}

	/* first weeek begins from which day */
	countToSeven = beginDays;

	/* Print calendar */
	while (day < numberOfDays+1)
	{
		/* when count to seven, it should print next week */
		if (countToSeven == 7)
		{
			printf("%3d\n", day);
			countToSeven = 0;
		}
		else
		{
			printf("%3d", day);
		}
		countToSeven++;
		day++;
	}
	printf("\n");
}