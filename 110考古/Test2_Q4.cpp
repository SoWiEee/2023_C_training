/*
* Read 100 integers from "Numbers_sorted.txt" and save them as an integer array.
* Output the search number and its index; else output the number not found message.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -999

int search(const int num[], int search, int size);
void clearBuffer();

int main()
{
	FILE *inp;		/* pointer to input file	 */
	int num[100];
	int inp_number;	/* input - the search number */
	int index;
	int i = 0;

	/* Prepare file for input */
	inp = fopen("Numbers_sorted.txt", "r");

	/* Check input file exist */
	if (inp == NULL)
	{
		printf("Input file no exist.\n");
		system("PAUSE");
		exit(1);
	}

	i = 0;

	while (i < 100)
	{
		fscanf(inp, " %d", &num[i]);
		i++;
	}

	do
	{
		/* Prompt the user to read a number from keyboard */
		printf("Enter a number: ", SENTINEL);
		scanf(" %d", &inp_number);

		/* 1 <= number <= 10000 */
		while (inp_number < 1 || inp_number > 10000)
		{
		clearBuffer();

		printf("Error! Enter the number: ");
		scanf(" %d", &inp_number);
		}

		index = search(num, inp_number, 100);

		/* Output the search number and its index; else output the number not found message */
		if (index != -1)
			printf("The search number is %d and its index is: %d\n", inp_number, index);
		else
			printf("The number not found !.\n");
	} while (inp_number != SENTINEL);

	/* close file */
	fclose(inp);

	system("PAUSE");
	return 0;
}

/* Binary Search */
int search(const int num[], int search, int size)
{
	int low = 0, high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (num[mid] == search)
		{
			return mid;
		}
		else if (num[mid] > search)
		{
			high = mid - 1;
		}
		else if (num[mid] < search)
		{
			low = mid + 1;
		}
	}

	return -1;

}

void clearBuffer()
{
	char discard = ' ';

	do
	{
		scanf("%c", &discard);
	} while (discard != '\n');
}