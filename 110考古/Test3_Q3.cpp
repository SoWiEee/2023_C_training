/*
* Read 100 names from "Girls_sorted.txt" and save them as a string array.
* Output the search name and its index; else output the number not found message.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTINEL "ZZZ"

int find_name(const char *list[], const char *target, int size);
void clearBuffer();

int main()
{
	FILE *inp;						/* pointer to input output file	*/
	char name[100][10];
	const char *name_search[100];
	char inp_name[10];				/* input - the search name */
	int index;
	int i = 0;

	/* Prepare file for input */
	inp = fopen("Girls_sorted.txt", "r");

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
		fscanf(inp, " %s", &name[i]);
		name_search[i] = name[i];
		i++;
	}

	do
	{
		/* Prompt the user to read a name from keyboard */
		printf("Enter a name: ", SENTINEL);
		scanf(" %s", inp_name);

		if (strcmp(inp_name, SENTINEL) != 0)
		{
			index = find_name(name_search, inp_name, 100);

			/* Output the search name and its index; else output the name not found message */
			if (index != -1)
				printf("The search name is %s and its index is: %d\n", inp_name, index);
			else
				printf("The name not found !.\n");

			clearBuffer();
		}

	} while (strcmp(inp_name, SENTINEL) != 0);

	/* close file */
	fclose(inp);

	system("PAUSE");
	return 0;
}

/* Binary Search */
int find_name(const char *list[], const char *target, int size)
{
		int low = 0, high = size - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (strcmp(list[mid], target) == 0)
			{
				return mid;
			}
			else if (strcmp(list[mid], target) > 0)
			{
				high = mid - 1;
			}
			else if (strcmp(list[mid], target) < 0)
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