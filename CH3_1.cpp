#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int
main(void)
{
	double purchase,     /*how much the car is*/
		down_payment,    
		annual_rate,     /*annual rate (percentage/100)*/
		P,               /*principal (the amount you borrow)*/
		I,               /*annual rate (in percentage)*/
		i,               /*monthly rate*/
		n,               /*total number of payments*/
		payment;         /*how much you will need to pay every month*/



	/*Get the number of purchase,down_payment,annual rate (in percentage) and total number of payments*/
	printf("Enter the purchase price of the car=>");
	scanf("%lf", &purchase);
	printf("Enter the down payment=>");
	scanf("%lf", &down_payment);
	printf("Enter the annual interest rate (percentage)=>");
	scanf("%lf", &I);
	printf("Enter the time period over which you will pay back the loan=>");
	scanf("%lf", &n);


	P = purchase - down_payment;                          /*calculate how much you borrow*/
	annual_rate = I / 100;                                /*turn percentage into regular value*/
	i = annual_rate / 12;                                 /*turn annual rate into monthly rate*/
	payment = (i * P) / (1 - (pow(1 + i, -n)));           /*calculate the monthly payment*/


	/*output the monthly payment*/
	printf("The amount borrowed is $%.2f\n", P);
	printf("The monthly payment is $%.2f", payment);      



	system("PAUSE");
	return(0);
}