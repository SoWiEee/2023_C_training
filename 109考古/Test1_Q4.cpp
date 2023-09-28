/*
 * Calculates BMI.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double BMI_calculate(double, double);	//calculate BMI

int main()
{
	double wt_lb = 0.0, ht_in = 0.0;	//input - weight and height
	double BMI = 0.0;					//BMI

	//read weight in pounds
	printf("Input weight in pounds=> ");
	scanf("%lf", &wt_lb);

	//read height in inches
	printf("Input height in inches=> ");
	scanf("%lf", &ht_in);
	
	BMI = BMI_calculate(wt_lb, ht_in);
	if (BMI < 18.5)
		printf("BMI is %.1lf, Underweight.\n", BMI);
	else if (BMI <= 24.9)
		printf("BMI is %.1lf, Normal.\n", BMI);
	else if (BMI <= 29.9)
		printf("BMI is %.1lf, Overweight.\n", BMI);
	else
		printf("BMI is %.1lf, Obese.\n", BMI);

	system("PAUSE");
	return 0;
}

double BMI_calculate(double weight, double height) {
	return (703 * weight) / pow(height, 2);
}