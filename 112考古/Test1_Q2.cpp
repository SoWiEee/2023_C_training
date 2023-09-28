#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int determineGrade(int, int, int);//this function is to determine the grade
int checkInputError(int);//this function is to check if the input is correct

int main()
{
	int Midterm, Final, Assighment;
	char grade;

	printf("Enter the mid-term exam score:");
	scanf("%d", &Midterm);//input score
	checkInputError(Midterm);

	printf("Enter the final exam score:");
	scanf("%d", &Final);
	checkInputError(Final);

	printf("Enter the assighment score:");
	scanf("%d", &assighment);
	checkInputError(Assighment);
	
	grade = determineGrade(Midterm, Final, Assighment);

	switch (grade)
	{
	case 'A':
		printf("Excellent!");
		break;
	case 'B':
		printf("Well done");
		break;
	case 'C':
		printf("OK!");
		break;
	case 'D':
		printf("Just passed!");
		break;
	case 'F':
		printf("Come back next year!");
		break;
	}

	system("PAUSE");
	return 0;
}

int determineGrade(int Midterm, int Final, int Assighment)
{
	int average;
	char grade;

	average = (Midterm + Final + assighment) / 3;//average scores

	if (average >= 90)
		grade = 'A';
	else if (average >= 70 && average < 90)
		if (Final >= 90)
			grade = 'A';
		else
			grade = 'B';
	else if (average >= 50 && average < 70)
		if ((Final + assighment) / 2 >= 70)
			grade = 'C';
		else
			grade = 'D';
	else
		grade = 'F';

	return grade;
}

int checkInputError(int input)
{
	if (input > 100 || input < 0)
	{
		printf("input error");
		system("PAUSE");
		exit(1);
	}
	return 0;
}
