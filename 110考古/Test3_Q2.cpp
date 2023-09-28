/*
 * Read 100 names from "Girls.txt" into a string array.
 * Sort and Outpute the array in alphabetical order.
 * Output the sorted names to "Girls_sorted.txt" file.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alpha_first(char *list[], int min_sub);
void select_sort(char *list[]);

int main()
{
	FILE *inp, *outp;		/* pointer to input and output file	*/
	int i = 0;
	char name[100][10];
	char *name_sort[100];

	/* Prepare file for input */
	inp = fopen("Girls.txt", "r");

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
		name_sort[i] = name[i];
		i++;
	}

	printf("original array:\n");

	i = 0;

	while (i < 100)
	{
		printf("%s\n", name[i]);
		i++;
	}

	select_sort(name_sort);

	printf("\n\nsorted array:\n");

	i = 0;

	while (i < 100)
	{
		printf("%s\n", name_sort[i]);
		i++;
	}

	if (!(outp = fopen("Girls_sorted.txt", "w")))
	{
		printf("Error!\n");
		return 0;
	}

	i = 0;

	while (i < 100)
	{
		fprintf(outp, "%s\n", name_sort[i]);
		i++;
	}



	/* close file */
	fclose(inp);
	fclose(outp);

	system("PAUSE");
	return 0;
}

/* Find s the index of the string that first alphabetically */
int alpha_first(char *list[], int min_sub) {
	
	int first, i;

	first = min_sub;
	for (i = min_sub + 1; i < 100; i++)
		if (strcmp(list[i], list[first]) < 0)
			first = i;

	return (first);
}

/* alphabetical order */
void select_sort(char *list[]) {
	
	int fill;			
	char *temp;
	int index_of_min;	

	for (fill = 0; fill < 100 - 1; fill++)
	{
		index_of_min = alpha_first(list, fill);

		if (fill != index_of_min) {
			temp = list[index_of_min];
			list[index_of_min] = list[fill];
			list[fill] = temp;
		}
	}
}