#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double func(double x, double n, double c)  /*double the "f(x)"*/
{
	return(pow(x, n) - c);
}
double func1(double x, double n)           /*double the "f'(x)"*/
{
	return(n * pow(x, (n - 1)));
}

int main()
{
	double x,   /*x^n=c*/
		n,
		c;

	printf("This program is to calculate the root 'x' of 'x^n=c' by giving the 'n' and 'c'.\n");
	printf("Enter (n,c) two numbers refers to 'x^n=c'=>");
	scanf("%lf%lf", &n, &c);             /*input "n" and "c"*/

	x = c / 2;                           /*pretend x = c / 2 as its initial guess*/

	/*we need f(x) = 0 or very close to 0, therefore, if f(x) isn't very close to 0, run the loop and make "x" smaller and smaller*/
	while (fabs(func(x, n, c)) > 0.000000001) 
	{
		x = x - (func(x, n, c) / func1(x, n));
	}

	printf("The root 'x' is =>%.6f .", x);  /*print out the result of the root "x"*/

	system("PAUSE");
	return(0);
}