/*
 * Calculates average value and determines maximum value of three floating points.
 */
#include <stdio.h>
#include <stdlib.h>

double readValue();						//read floating point
double findMax(double, double, double);	//find maximum value of three double values
double avgABC(double, double, double);	//calculate average value of three double values

int main()
{
	double a = 0.0, b = 0.0, c = 0.0;	//input - 3 floating points
	double temp = 0.0;					//temp value for switch

	//read 3 floating points
	a = readValue();
	b = readValue();
	c = readValue();

	printf("User input a=%.2lf, b=%.2lf, and c=%.2lf\n", a, b, c);

	//switch a and b
	temp = a;
	a = b;
	b = temp;

	printf("After switch a and b, a=%.2lf, b=%.2lf, and c=%.2lf\n", a, b, c);
	printf("The maximum value is %.2lf\n", findMax(a, b, c));
	printf("The average value is %.2lf\n", avgABC(a, b, c));

	system("PAUSE");
	return 0;
}

double readValue() {
	double value = 0.0;

	printf("Input floating point=> ");
	scanf("%lf", &value);

	return value;
}

double findMax(double a, double b, double c) {
	if (a >= b&&a >= c)
		return a;
	else if (b >= a&&b >= c)
		return b;
	else
		return c;
}

double avgABC(double a, double b, double c) {
	return (a + b + c) / 3.0;
}