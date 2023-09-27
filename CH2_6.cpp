#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    /*printf, scanf definitions*/
#include<stdlib.h>    /*system definition*/

int
main(void)
{
	char desired_grade;     /*the desired grade*/

	double minimum,         /*the minimum average required*/
		current,            /*the current average in course*/
		percentage,         /*how much the final counts as a percentage of the course grade*/
		needed_score;       /*how much score yoou need to get the desired grade*/

	printf("Enter desired grade> ");
	scanf("%c", &desired_grade);                          /*enter desired grade*/
	printf("Enter minimum average required> ");  
	scanf("%lf", &minimum);                               /*enter the minimum average required*/
	printf("Enter current average in course> ");
	scanf("%lf", &current);
	printf("Enter how much the final counts as a percentage of the course grade> ");     /*enter how much the final counts as a percentage of the course grade*/
	scanf("%lf", &percentage);


	needed_score = (minimum - current * (100 - percentage) / 100) / (percentage / 100);  /*compute the needed score*/

	printf("You need a score of %.2f on the final to get a %c", needed_score, desired_grade);

	system("PAUSE");

	return (0);
}