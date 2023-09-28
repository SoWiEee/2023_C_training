/*
*	The program need you to key in the scores(between 0 and 100) of mid - term exam.
*	However,calculates average of the three scores.
*	Used 'determineGrade' function to output student's grade.
*	Then used switch to determines grade class and display message.
*
*	Grade	Message
*	A		Excellent!
*	B		Well done!
*	C		OK!
*	D		Just passed!
*	F		Come back next year!
*/

#define _CRT_SECURE_NO_WARNINGS	//Use 'scanf' function.
#include <stdio.h>				//Include library.
#include <stdlib.h>

char determineGrade(int, int, int, int);	//Determines a student's grade on the following rules.

int main() {

	int mid_exam, final_exam, assignment;	//Stored student's scores of mid exam,final exam,assignment.
	int avg_score;							//Stored average of all scores.
	char grade;								//Stored student's grade or 'determineGrade' function output.

	printf("Please key in mid exam score(between 0 and 100):\n");
	scanf("%d", &mid_exam);	//Key in mid exam score.
	if (mid_exam < 0 || mid_exam > 100) {
		printf("Error! Mid_exam range must be between 0 and 100!\n");
		system("pause");
		exit(0); //Abort
	}
	printf("Please key in final exam score(between 0 and 100):\n");
	scanf("%d", &final_exam);	//Key in final exam score.
	if (final_exam < 0 || final_exam > 100) {
		printf("Error! Final_exam range must be between 0 and 100!\n");
		system("pause");
		exit(0); //Abort
	}
	printf("Please key in assignment score(between 0 and 100):\n");
	scanf("%d", &assignment);	//Key in assignment score.
	if (assignment < 0 || assignment > 100) {
		printf("Error! Assignment score range must be between 0 and 100!\n");
		system("pause");
		exit(0); //Abort
	}

	avg_score = (int)((mid_exam + final_exam + assignment) / 3.0 + 0.5);	//Compute average of all scores(Round off to the 1nd decimal place).
	printf("Average score : %d\n", avg_score);
	grade = determineGrade(mid_exam, final_exam, assignment, avg_score);	//Determine a student's grade.

	switch (grade)	//Determine grade,and display message.
	{
	case 'A':
		printf("Excellent!");
		break;
	case 'B':
		printf("Well done!");
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
	printf("\n");

	system("pause");
	return 0;
}

/*Determine student's Grade.*/
char determineGrade(int mid_exam, int final_exam, int assignment, int avg_score) {
	if (avg_score >= 90)
		/*Average score is 90 or more.*/
		return 'A';
	else if (avg_score >= 70) {
		/*Average score is less than 90 and 70 or more.*/
		if (final_exam > 90)
			/*Final score is more than 90.*/
			return 'A';
		else
			return 'B';
	}
	else if (avg_score >= 50) {
		/*Average score is less than 70 and 50 or more.*/
		if ((int)(((final_exam + assignment) / 2.0) + 0.5) > 70)
			/*Average of the final and assignment scores is greater than 70(Round off to the 1nd decimal place).*/
			return 'C';
		else
			return 'D';
	}
	else
		/*Average score is less than 50.*/
		return 'F';
}