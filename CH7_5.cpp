#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int code[ 12 ];                                              /*define the code that have 12 digits*/
	
	for (int q = 0; q < 4; q ++)                                 /*do the program four times to check four datas*/
	{
		int result_digit, odd = 0, even = 0;                     /*the result of strp 2, the odd and even digit of the data*/
		printf("Enter the barcode =>");                          /*prompt the user to input the data*/

		for (int i = 0; i < 12; i++)                             /*do the loop to scan 12 digits of the data*/
		{
			scanf("%d", &code[i]);
		}
		for (int j = 0; j < 11; j += 2)                          /*do the loop to sum up the odd digit*/
		{
			odd += code[j];
		}
		for (int k = 1; k < 11; k += 2)                          /*do the loop to sum up the even digit*/
		{
			even += code[k];
		}

		result_digit = odd * 3 + even;                           /*calculate the result of step 2*/
		printf("The result of step 2 is %d.\n", result_digit);   /*output the result of the result number*/
		result_digit %= 10;                                      /*get the last digit of the result number*/

		if (result_digit == 0)                                   /*if the last digit equals to 0 and the last number of the data, print 'validated'*/
		{                                                        /*else, print error*/
			if (result_digit == code[11])
			{
				printf("validated.\n\n");
			}
			else
			{
				printf("error on barcode.\n\n");
			}
		}
		else if (result_digit != 0)                             /*if the last digit doesn't equals to 0 and equals to */
		{                                                       /*(10-the last number of the data), print 'validated'*/
			if ((10 - result_digit) == code[11])                /*else, print error*/
			{
				printf("validated.\n\n");
			}
			else
			{
				printf("error on barcode.\n\n");
			}
		}
	}
	system("PAUSE");
	return(0);

}