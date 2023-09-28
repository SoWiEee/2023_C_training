/*
 * Reads scores of mid-term exam,final exam and assignment,
 * then determines student's grade.
 */
#include <stdio.h>
#include <stdlib.h>

int readScore();												//read score
char determineGrade(int, int, int);								//calculate average score and determine grade
void printMessage(char, double);								//print average score,grade and message

int main()
{
	int mid_score = 0, final_score = 0, assignment_score = 0;	//input - scores

	//read mid-term exam,final exam and assignment scores
	mid_score = readScore();
	final_score = readScore();
	assignment_score = readScore();
	
	printMessage(determineGrade(mid_score, final_score, assignment_score), (mid_score + final_score + assignment_score) / 3.0);

	system("PAUSE");
	return 0;
}

int readScore() {
	int score = 0;

	printf("Input score=> ");
	scanf("%d", &score);

	//score must between 0 and 100
	//if not, print error message and exit program
	if (score<0 || score>100)
	{
		printf("ERROR! 0 <= score <= 100, program end...\n");
		system("PAUSE");
		exit(0);
	}
	return score;
}

char determineGrade(int mid_score, int final_score, int assignment_score) {
	double averageGrade = (mid_score + final_score + assignment_score) / 3.0;

	if (averageGrade >= 90)
		return 'A';
	else if (averageGrade >= 70)
	{
		if (final_score > 90)
			return 'A';
		else
			return 'B';
	}
	else if (averageGrade >= 50)
	{
		if ((final_score + assignment_score) / 2.0 > 70)
			return 'C';
		else
			return 'D';
	}
	else
		return 'F';
}

void printMessage(char grade, double score) {
	printf("Average score is %.2lf\nGrade is %c\n", score, grade);
	switch (grade) {
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
}