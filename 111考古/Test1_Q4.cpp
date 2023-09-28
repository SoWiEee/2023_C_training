/*
*	The program need you to key in starting year, month, day and ending year, month, day.
*	Then,used 'calcMonth' function to calculate the number of months between two dates.
*/

#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function.
#include <stdio.h>				//Include library.
#include <stdlib.h>

int calcMonth(int, int, int, int, int, int);	//Calculate the number of months between two dates.

int main() {

	int start_year, start_month, start_day;		//Stored start date.
	int ending_year, ending_month, ending_day;	//Stored ending date.
	int months;									//Stored 'calcMonth' function result.

	printf("Note:Start date must earlier than ending date!\n");
	printf("Please key in year of start:\n");
	scanf("%d", &start_year);					//Key in start of year.
	if (start_year < 1) {	//Year must bigger than 0.
		printf("Error from start year!\nStart year : %d format isn't real!\n", start_year);
		system("pause");
		exit(0);
	}
	printf("Please key in month of start:\n");
	scanf("%d", &start_month);					//Key in start of month.
	if (start_month < 1 || start_month>12) {	//Month must be between 1 and 12.
		printf("Error from start month!\nStart year/month : %d/%d format isn't real!\n", start_year, start_month);
		system("pause");
		exit(0);
	}
	printf("Please key in day of start:\n");
	scanf("%d", &start_day);					//Key in start of day.
	if (start_month >= 1 && start_month <= 7) {	//Month is between 1 and 7.
		if (start_month % 2 != 0) {				//Month is 1 or 3 or 5 or 7.
			if (start_day > 31 || start_day < 1) {
				printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
				system("pause");
				exit(0);
			}
		}
		else {									//Month is 2 or 4 or 6.
			if (start_month == 2) {				//Month is 2.
				if (start_year % 4 == 0) {		//Year is a multiple of 4.
					if (start_day > 29 || start_day < 1) {
						printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
						system("pause");
						exit(0);
					}
				}
				else {
					if (start_day > 28 || start_day < 1) {
						printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
						system("pause");
						exit(0);
					}
				}
			}
			else {								//Month is 4 or 6
				if (start_day > 30 || start_day < 1) {
					printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
					system("pause");
					exit(0);
				}
			}
		}
	}
	else {										//Month is between 8 and 12.
		if (start_month % 2 != 0) {				//Month is 9 or 11.
			if (start_day > 30 || start_day < 1) {
				printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
				system("pause");
				exit(0);
			}
		}
		else {									//Month is 8 or 10 or 12.
			if (start_day > 31 || start_day < 1) {
				printf("Error from start date!\nStart date : %d/%d/%d format isn't real!\n", start_year, start_month, start_day);
				system("pause");
				exit(0);
			}
		}
	}
	printf("Please key in year of ending:\n");
	scanf("%d", &ending_year);					//Key in ending of year.
	if (ending_year < 1) {						//Year must bigger than 0.
		printf("Error from ending year!\nEnding year : %d format isn't real!\n", ending_year);
		system("pause");
		exit(0);
	}
	printf("Please key in month of ending:\n");
	scanf("%d", &ending_month);					//Key in ending of month.
	if (ending_month < 1 || ending_month>12) {	//Month must be between 1 and 12.
		printf("Error from ending month!\nEnding year/month : %d/%d format isn't real!\n", ending_year, ending_month);
		system("pause");
		exit(0);
	}
	printf("Please key in day of ending:\n");
	scanf("%d", &ending_day);					//Key in ending of day.
	if (ending_month >= 1 && ending_month <= 7) {//Month is between 1 and 7.
		if (ending_month % 2 != 0) {			//Month is 1 or 3 or 5 or 7.
			if (ending_day > 31 || ending_day < 1) {
				printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
				system("pause");
				exit(0);
			}
		}
		else {									//Month is 2 or 4 or 6.
			if (ending_month == 2) {			//Month is 2.
				if (ending_year % 4 == 0) {		//Year is a multiple of 4.
					if (ending_day > 29 || ending_day < 1) {
						printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
						system("pause");
						exit(0);
					}
				}
				else {
					if (ending_day > 28 || ending_day < 1) {
						printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
						system("pause");
						exit(0);
					}
				}
			}
			else {								//Month is 4 or 6
				if (ending_day > 30 || ending_day < 1) {
					printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
					system("pause");
					exit(0);
				}
			}
		}
	}
	else {										//Month is between 8 and 12.
		if (ending_month % 2 != 0) {			//Month is 9 or 11.
			if (ending_day > 30 || ending_day < 1) {
				printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
				system("pause");
				exit(0);
			}
		}
		else {									//Month is 8 or 10 or 12.
			if (ending_day > 31 || ending_day < 1) {
				printf("Error from ending date!\nEnding date : %d/%d/%d format isn't real!\n", ending_year, ending_month, ending_day);
				system("pause");
				exit(0);
			}
		}
	}

	if (start_year < ending_year)
		months = calcMonth(start_year, start_month, start_day, ending_year, ending_month, ending_day);
	else if (start_year == ending_year) {		//Start year is the same as ending year,so check month.
		if (start_month < ending_month)
			months = calcMonth(start_year, start_month, start_day, ending_year, ending_month, ending_day);
		else if (start_month == ending_month) {	//Start month is the same as ending month,so check day.
			if (start_day <= ending_day)
				months = calcMonth(start_year, start_month, start_day, ending_year, ending_month, ending_day);
			else {								//Erro from day.
				printf("Error from day!\nStart date(%d/%d/%d) later than ending date(%d/%d/%d).\n", start_year, start_month, start_day, ending_year, ending_month, ending_day);
				system("pause");
				exit(0);
			}
		}
		else {									//Erro from month.
			printf("Error from month!\nStart year/month(%d/%d) later than ending year/month(%d/%d).\n", start_year, start_month, ending_year, ending_month);
			system("pause");
			exit(0);
		}
	}
	else {										//Erro from year.
		printf("Error from year!\nStart year(%d) later than ending year(%d).\n", start_year, ending_year);
		system("pause");
		exit(0);
	}

	if (months < 2)
		printf("%d / %d / %d~%d / %d / %d ---> %dmonth\n", start_year, start_month, start_day, ending_year, ending_month, ending_day, months);
	else
		printf("%d / %d / %d~%d / %d / %d ---> %dmonths\n", start_year, start_month, start_day, ending_year, ending_month, ending_day, months);

	system("pause");
	return 0;

}

/*Function will calculate the number of months between two dates.*/
int calcMonth(int start_year, int start_month, int start_day, int ending_year, int ending_month, int ending_day) {
	if (start_year == ending_year) {
		/*When start with the same year as the ending,just care month and day.*/
		if (start_day <= ending_day) {
			/*Start more than ending of the day.*/
			return ending_month - start_month + 1;
		}
		else {
			/*Ending more than start of the day.*/
			return ending_month - start_month;
		}
	}
	else {
		/*When different from the start and the ending of the year.*/
		if (start_month <= ending_month) {
			/*Ending more than start of the month.*/
			if (start_day <= ending_day) {
				/*Ending more than start of the day.*/
				return (ending_year - start_year) * 12 + ending_month - start_month + 1;
			}
			else {
				/*Start more than ending of the day.*/
				return (ending_year - start_year) * 12 + ending_month - start_month;
			}
		}
		else {
			/*Start more than ending of the month.*/
			if (start_day <= ending_day) {
				/*Ending more than start of the day.*/
				return (ending_year - start_year) * 12 - start_month + ending_month + 1;
			}
			else {
				/*Start more than ending of the day.*/
				return (ending_year - start_year) * 12 - start_month + ending_month;
			}

		}
	}
}