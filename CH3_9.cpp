#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int flu(int day)
{
	int cases;         /*how many cases for the flu*/

	double x;          /*the model which a math professer proposes to predict the total number of cases by day number*/

	x = 40000 / (1 + 39999 * exp(-0.24681));       /*calculate the model*/
	cases = pow(x, day);                           /*calculate the cases by day number*/

	return(cases);
}

int main(void)
{
	int day;
	
		printf("FIU EPIDEMIC PREDICTIONS BASED ON ELAPSED DSYS SINCE FIRST CASE REPORT\n");
		
		printf("\nEnter day number>>");                                                  /*Enter the day number since the flu begins*/
		scanf("%d", &day);
		printf("By day %d,model predicts %d cases total.\n", day, flu(day));             /*output the day number and the cases*/

		printf("\nEnter day number>>");
		scanf("%d", &day);
		printf("By day %d,model predicts %d cases total.\n", day, flu(day));

		printf("\nEnter day number>>");
		scanf("%d", &day);
		printf("By day %d,model predicts %d cases total.\n", day, flu(day));

    
	system("PAUSE");
	return(0);
	
}
