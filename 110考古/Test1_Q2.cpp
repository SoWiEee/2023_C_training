/*
 * Find the maximum value and calculate the average value of three floating points
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

double findMax(double, double, double);  /* Find the maximum value of the three values */
double avgABC(double, double, double);   /* Calculate the average of the three values  */

int main()
{
	double a = 0.0, b = 0.0, c = 0.0;	/* input - 3 floating points */
	double temp = 0.0;					/* temp value for switch     */

	/* Read three floating points */
	printf("Enter three floating points> ");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	/* Print out three floating points */
	printf("User input a=%.2lf, b=%.2lf, and c=%.2lf\n", a, b, c);

	/* switch a and b */
	temp = a;
	a = b;
	b = temp;
	
	/* Print out three values, the maximum value , and the average value */
	printf("After switch a and b, a=%.2lf, b=%.2lf, and c=%.2lf\n", a, b, c);
	printf("The maximum value is %.2lf\n", findMax(a, b, c));
	printf("The average value is %.2lf\n", avgABC(a, b, c));

	system("PAUSE");
	return 0;
}

double findMax(double a, double b, double c) 
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else
		return c;
}

double avgABC(double a, double b, double c) 
{
	return (a + b + c) / 3.0;
}