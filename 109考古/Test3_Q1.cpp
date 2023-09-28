#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int error;			/* flag indicating presence of an error 		*/
	char discard;		/* unprocessd character from input line 		*/
	int barcode[12];	/* store the barcode 							*/
	int odd_sum = 0;	/* sum of the digits in odd-numbered positions 	*/
	int even_sum = 0;	/* sum of the digits in even-numbered positions */
	int check_num;		/* use to check the final digit of barcode 		*/
	int i; 				/* use in for-loop as an index 					*/

	do
	{
		/* no errors detected yet */
		error = 0;

		/* read the barcode */
		printf("Input the 12 digits of a barcode separated by space=> \n");
		for (i = 0; i < 12; i++)
		{
			scanf("%d", &barcode[i]);
			/* each digit of barcode must between 0 to 9 */
			if (barcode[i] > 9 || barcode[i] < 0 || isdigit(barcode[i]))
			{
				error = 1;
				printf("Invalid - please input again\n");
				break;
			}
		}

		/* Discard extra input character */
		do
		{
			scanf("%c", &discard);
		} while (discard != '\n');

	} while (error);

	/* calculate odd_sum */
	for (i = 0; i < 12; i += 2)
	{
		odd_sum += barcode[i];
	}
	odd_sum *= 3;

	/* calculate even_sum */
	for (i = 1; i < 10; i += 2)
	{
		even_sum += barcode[i];
	}

	/* if the last digit of odd_sum + even_sum is 0, check_num is 0
	   if not, check_num is 10 - the last digit */
	if ((odd_sum + even_sum) % 10 == 0)
		check_num = 0;
	else
		check_num = 10 - (odd_sum + even_sum) % 10;

	/* check the barcode is validated or not and print the result */
	if (check_num == barcode[11])
		printf("validated.\n");
	else
		printf("error in barcode.\n");

	/* print result from step 1 and 2 */
	printf("Result from step 1: %d.\n", odd_sum);
	printf("Result from step 2: %d.\n", odd_sum + even_sum);

	system("pause");
	return 0;
}