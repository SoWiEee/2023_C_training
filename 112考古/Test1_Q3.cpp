#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int calcMonth(int, int, int, int, int, int);//this function is to calculate the month
int checkInputError(int, int, int);//this function is to check if the input is correct
int main()
{
	int startyear, startmonth, startday;
	int endyear, endmonth, endday;
	int month;

	printf("Enter the starting year:");
	scanf("%d", &startyear);
	printf("Enter the starting month:");
	scanf("%d", &startmonth);
	printf("Enter the starting day:");
	scanf("%d",&startday);
	checkInputError(startyear, startmonth, startday);

	printf("Enter the ending year:");
	scanf("%d", &endyear);
	printf("Enter the ending month:");
	scanf("%d", &endmonth);
	printf("Enter the ending day:");
	scanf("%d", &endday);
	checkInputError(endyear, endmonth, endday);

	month = calcMonth(startyear, startmonth, startday, endyear, endmonth, endday);
	//calculate the month
	printf("The tatal month is %d.", month);

	system("Pause");
	return 0;
}

int calcMonth(int startyear, int startmonth, int startday, int endyear, int endmonth, int endday)
{
	int year;
	int month;
	int total_month;

	year = endyear - startyear;
	month = endmonth - startmonth;


	total_month = year * 12 + month;

	if ((endday - startday) > 0)
		total_month += 1;
	return total_month;
}

int checkInputError(int year,int month,int day)
{
	if (year < 0)//check year >0
	{
		printf("input error");
		system("Pause");
		exit(1);
	}
	if (month <= 0 || month>12)//check if month is between 1~12
	{
		printf("input error");
		system("Pause");
		exit(1);
	}
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0))//leap year
	{	
		if (month == 2)
		{
			if (day <= 0 || day>29)
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
		else if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12)//31days month
		{
			if (day <= 0 || day>31)
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
		else
		{
			if (day <= 0 || day>30)//30days month
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
	}
	else
	{
		if (month == 2)//common year
		{
			if (day <= 0 || day>28)
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
		else if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12)
		{
			if (day <= 0 || day>31)
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
		else
		{
			if (day <= 0 || day>30)
			{
				printf("input error");
				system("Pause");
				exit(1);
			}
		}
	}
	
	return 0;
}