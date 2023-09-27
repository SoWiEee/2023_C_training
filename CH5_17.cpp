#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double g(double x)            /*double the g(x)*/
{
	x = x * x * sin(x);
	return(x);
}

double h(double x)            /*double the h(x)*/
{
	x = sqrt(4 - (x * x));
	return(x);
}

void trap(double a, double b, double n, char f);  /*void the function "trap"*/

int main()
{
	double a,  /*the smaller value of the area under the curve*/
		b,     /*the bigger value of the area under the curve*/
		n;     /*how much piece you want to cut apart of the area*/
		
	char f;    /*which type of the function you want to use*/
	
	printf("Enter 'g' or 'h' of the type of the function =>");               /*input the type of the function you want to use*/
	scanf("%c", &f);
	printf("Enter the 'a' and 'b' of the area under the curve that between lines x=a and x=b(b>a)=>");     /*input the range of the area*/
	scanf("%lf%lf", &a, &b);
	printf("Enter the 'n' of how much peices of the curve =>");              /*input the amount of the pieces*/
	scanf("%lf", &n);
	
    trap(a, b, n, f);      /*call the function "trap"*/

	system("PAUSE");
	return(0);
}

void trap(double a,double b, double n, char f)
{
	double T,     /*the formula of the trapezoidal rule approximates*/
		sum=0,    /*the sum of each £U*/
		length;   /*the length of each piece*/
	int i;

	length = (b - a) / n;    /*the length of each piece*/

	if (f == 'g')           /*if the type of the function is 'g'*/
	{
		for (i = 1; i < n; i++)                           /*i=1~(n-1)*/
		{
			sum += g(a + length * i);                     /*calculate the £U of the formula*/
		}
		T = length / 2 * (g(a) + g(b) + 2 * sum);         /*the formula of the trapezoidal rule approximates*/

		printf("The sum of the areas is %.5f .\n", T);    /*output the result*/
	}
	else if (f == 'h')      /*if the type of the function is 'h'*/
	{
		for (i = 1; i < n; i++)                           /*i=1~(n-1)*/
		{
			sum += h(a + length * i);                     /*calculate the £U of the formula*/
		}
        T = length / 2 * (h(a) + h(b) + 2 * sum);         /*the formula of the trapezoidal rule approximates*/

		printf("The sum of the areas is %.5f .\n", T);    /*output the result*/
	}
}