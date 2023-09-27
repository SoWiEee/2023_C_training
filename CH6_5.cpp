#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int reverse(int num)        /*the function that reverse the number*/
{
	int reverse_num = 0; 
		while (num != 0)                                      /*while num isn't 0, run the loop*/
		{
			reverse_num = reverse_num * 10 + (num % 10);      /*get the last number everytime and while enter next round, times 10, plus the next last number */
			num /= 10;                                        /*divide 10 to remove the last number every round*/
		}
	
	return (reverse_num);
}
int prime(int num)         /*the function that check the number is prime or not*/
{
	int i;

	if (num == 1)                     /*if the number is 1, it isn't a prime*/
	{
		return(0);
	}
	else if (num != 1)                /*if the number isn't 1, calculate if it can divide exactly by 2 to the number smaller than it*/
	{                                 /*if can, it isn't a prime.if can't, it is a prime*/
		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				return(0);
			}
		}
	}
	return(1);
}
void palindrome(int num, int reverse_num) /*the function that check the number is palindrome or not*/
{
	if (num == reverse(num))                                /*if the number equals to the number after reversed, it is a palindrome*/
	{
		printf("The number is a palindrome number.\n\n");
	}
	else                                                    /*if the number doesn't equals to the number after reversed, it isn't a palindrome*/
	{
		printf("The number isn't a palindrome number.\n\n");
	}
}
void nums(int *num);                 /*void the function "num"*/
int main()
{
    int num;

	printf("Enter numbers=>");        /*input the numbers*/
	scanf("%d",&num);

	while (num != EOF)                /*while num isn't '\n',which cause the scan of the %d returns -1, run the loop*/
	{
		nums(&num);                   /*run the function "num"*/
		scanf("%d", &num);            /*scan the next number after the round*/
		
	}
	
	return(0);
}

void nums(int *num)
{
	printf("\nThe number is %d.\n", *num);                          /*output which number is it*/
	printf("The number after reversed is %d.\n", reverse(*num));    /*output the revered number*/
	if (prime(*num) == 0)                                           /*output whether the number is prime or not*/
	{
		printf("The number isn't prime.\n");
	}
	else if (prime(*num) == 1)
	{
		printf("The number is prime.\n");
	}
	palindrome(*num, reverse(*num));                                /*output whether the number is palindrome or not*/
}
