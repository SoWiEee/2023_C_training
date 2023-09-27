#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	double wt_lb,     /*weight in pounds*/
		ht_in,        /*height in inches*/
		BMI;        
	

	/*Enter weights and height*/
	printf("Enter weight in pounds=>");  
	scanf("%lf", &wt_lb);
	printf("Enter height in inches=>");
	scanf("%lf", &ht_in);

	BMI = 703 * wt_lb / (ht_in * ht_in);              /*calculate the BMI*/


	/*give conditions and output the result of the weight status*/
	if (BMI < 18.5)
	{
		printf("The weight status is => Underweight");
	}
	else if (BMI >= 18.5 && BMI <= 24.9)
	{
		printf("The weight status is => Normal");
	}
	else if (BMI >= 25.0 && BMI <= 29.9)
	{
		printf("The weight status is => Overweight");
	}
	else if (BMI >= 30.0)
	{
		printf("The weight status is => Obese");
	}

	system("PAUSE");
	return (0);
}