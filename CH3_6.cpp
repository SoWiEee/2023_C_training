#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fps(int m, double s)                   /*fps=>speed in feet per second*/
{
	m = m * 60;                                    /*turn minutes into seconds*/
	s = s + m;
	
	return(5280 / s);                              /*calculate the fps*/
}

double mps(int m, double s)                  /*mps=>speed in meters per second*/
{
	m = m * 60;                                    /*turn minutes into seconds*/
	s = m + s;
	
	return((5280.0 / 3282 * 1000) / s);            /*calculate the mps*/
}



int
main(void)
{
	int m;
	double s;

	printf("Enter No.1's minutes and seconds=>");                          /*Enter how long the runner run for one mile*/
	scanf("%d%lf", &m, &s);
	printf("The No.1 runner's fps is %lf\n", fps(m, s));                   /*output the fps*/
	printf("The No.1 runner's mps is %lf\n", mps(m, s));                   /*output the mps*/

	printf("\nEnter No.2's minutes and seconds=>");
	scanf("%d%lf", &m, &s);
	printf("The No.2 runner's fps is %lf\n", fps(m, s));
	printf("The No.2 runner's mps is %lf\n", mps(m, s));
	
	printf("\nEnter No.3's minutes and seconds=>");
	scanf("%d%lf", &m, &s);
	printf("The No.3 runner's fps is %lf\n", fps(m, s));
	printf("The No.3 runner's mps is %lf\n", mps(m, s));

	printf("\nEnter No.4's minutes and seconds=>");
	scanf("%d%lf", &m, &s);
	printf("The No.4 runner's fps is %lf\n", fps(m, s));
	printf("The No.4 runner's mps is %lf\n", mps(m, s));


	system("PAUSE");
	return(0);
}