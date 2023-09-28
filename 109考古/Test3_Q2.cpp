#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int arr_size = 100;	/* array size */

void selection_sort(char *list[]);
int alpha_first(char *list[], int min_sub);

int main(void)
{
	FILE *inputFile;					/* pointer to input file				*/
	FILE *outputFile;					/* pointer to output file				*/
	char names[arr_size][10];			/* store the original array of names	*/
	char *alpha[arr_size];				/* list of pointers to names			*/
	int i;								/* use in for-loop as an index			*/

	/* prepare file for input */
	inputFile = fopen("Girls.txt", "r");

	/* check input file exist */
	if (inputFile == NULL)
	{
		printf("input file no exist.\n");
		system("pause");
		exit(1);
	}

	/* Prepare files for output file */
	outputFile = fopen("Girls_sorted.txt", "w");

	/* input an item from input file */
	for (i = 0; i < arr_size; i++)
	{
		fscanf(inputFile, "%s", names[i]);
	}

	/* print the original array of names */
	printf("original string array.\n");
	for (i = 0; i < arr_size; i++)
	{
		printf("%s\n", names[i]);
	}

	/* fills array of pointers and sorts */
	for (i = 0; i < arr_size; ++i){
		alpha[i] = names[i];
	}

	/* call function selection_sort */
	selection_sort(alpha);

	printf("\n\n\n");

	/* print the sorted array of names and output it in a file */
	printf("sorted string array.\n");
	for (i = 0; i < arr_size; i++)
	{
		printf("%s\n", alpha[i]);
		fprintf(outputFile, "%s\n", alpha[i]);
	}

	/* close file */
	fclose(inputFile);
	fclose(outputFile);

	system("pause");
	return 0;
}

/* orders the pointers in array list so they access strings in alphabetical order */
void selection_sort(char *list[]) {
	int fill;			/* index of element to contain next string in order	*/
	char *temp;			
	int index_of_min;	/* index of next string in order					*/

	for (fill = 0; fill < arr_size - 1; fill++)
	{
		/* call function alpha_first to get the smallest value in names */
		index_of_min = alpha_first(list, fill);

		/* if this index is not the index of smallest value in names, swap them */
		if (fill != index_of_min) {
			temp = list[index_of_min];
			list[index_of_min] = list[fill];
			list[fill] = temp;
		}
	}
}

/* find the index of the string that comes first alphabetically in list */
int alpha_first(char *list[], int min_sub) {
	int first, i;
	
	first = min_sub;
	for (i = min_sub + 1; i < arr_size; i++)
		if (strcmp(list[i], list[first]) < 0)
			first = i;
	
	return (first);
}