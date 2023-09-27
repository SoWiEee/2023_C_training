#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>      /*printf, scanf definitions*/
#include<stdlib.h>     /*system definition*/

int
main(void)
{
	double thour,         /*the passed hours*/
		   tmin,          /*the passed minutes*/
		   time,          /*the time passed since the power failure*/
		   Temperature;   /*the temperature after the passed time*/

	printf("Enter the elapsed time since a power failure:");
	scanf("%lf%lf", &thour, &tmin);                                      /*when using two"%lf"together, you can enter them in the same line*/
																		 /*the"&thour"stands for the "%lf" in the front ,and the "&tmin" stands for the one in the back*/
	tmin = tmin / 60;                                                    /*change minutes into hours*/
	time = thour + tmin;                                                 
	

	Temperature = 4 * time * time / (time + 2) - 20;

	printf("The temperature is %.2f¢J", Temperature);


	system("PAUSE");
	return (0);
}