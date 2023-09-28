/*
 * Read scores of mid-term exam, final exam , and assignment,
 * then determines a student's grade.
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char determineGrade(int, int, int);	 /* Determine grade */

int main()
{
	int mid_score = 0, final_score = 0, assignment_score = 0;    /* input - scores             */
	double average_score;                                        /* output - the average score */
	char grade;                                                  /* output - the grade         */

	/* Read mid-term exam score */
	printf("Enter the score of mid-term exam(between 0 and 100)> ");
	scanf("%d", &mid_score);
	
	/* Read final exam score */
	printf("\nEnter the score of final exam(between 0 and 100)> ");
	scanf("%d", &final_score);

	/* Read assignment score */
	printf("\nEnter the score of assignment(between 0 and 100)> ");
	scanf("%d", &assignment_score);

	/* score must between 0 and 100 */
	if (mid_score < 0 || mid_score > 100 || final_score < 0 || final_score > 100 || assignment_score < 0 || assignment_score > 100)
	{
		printf("\nERROR! Score must between 0 and 100!\n");
		system("PAUSE");
		exit(0);
	}
	
	/* Calculate the average score */
	average_score = (mid_score + final_score + assignment_score) / 3.0;
	
	grade = determineGrade(mid_score, final_score, assignment_score);
    
	/* Print out the average score and the grade */
	printf("\nAverage score is %.2lf\nGrade is %c\n", average_score, grade);
	
	/* Print out the message */
	switch (grade)
	{
		case 'A':
			printf("Excellent!\n");
			break;
		case 'B':
			printf("Well done!\n");
			break;
		case 'C':
			printf("OK!\n");
			break;
		case 'D':
			printf("Just passed!\n");
			break;
		case 'F':
			printf("Come back next year!\n");
	}
	
	system("PAUSE");
	return 0;
}

char determineGrade(int mid_score, int final_score, int assignment_score) 
{
	averageGrade = (mid_score + final_score + assignment_score) / 3.0;
	
	if (averageGrade >= 90)
		return 'A';
	else if (averageGrade >= 70 && averageGrade < 90)
	{
		if (final_score > 90)
			return 'A';
		else
			return 'B';
	}
	else if (averageGrade >= 50 && averageGrade < 70)
	{
		if ((final_score + assignment_score) / 2.0 > 70)
			return 'C';
		else
			return 'D';
	}
	else
		return 'F';
}