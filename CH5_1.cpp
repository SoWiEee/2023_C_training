#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int digit(int n){
	int digit,                     /*each digit of the number*/
		sum=0;                     /*the sum of each digit*/

	while (n != 0){
		digit = n % 10;            /*get each digit*/
		
		printf("%d ", digit);
		
		n = n / 10;                /*remove tha digit you get*/ /*it can be remove because 'n' use 'int'*/
		sum += digit;              /*sum=sum+digit by each round*/
	}
	if (sum % 9 == 0)              /*is divisible by 9*/
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int main(void){
	int n;                         /*the number you input*/

	printf("Enter a number=>");    /*input the number*/
	scanf("%d",&n);

	printf("\nWhether the number is divisible by 9?(yes=1,no=0)=>%d\n",digit(n));  /*output the result*/

	system("pause");
	return 0;
}
