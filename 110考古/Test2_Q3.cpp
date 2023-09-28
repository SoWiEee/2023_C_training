/*
 * Read 100 integers from "Numbers.txt" into an integer array.
 * Sort and Outpute the array in ascending order.
 * Output the sorted numbers to "Numbers_sorted.txt" file.
 */
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void select_sort(int array[], int n);

int main()
{
	FILE *inp, *outp;	/* pointer to input and output file	*/
	int i = 0;
	int num[100]; 		
	int num_sort[100];	

	/* Prepare file for input */
	inp = fopen("Numbers.txt", "r");

	/* Check input file exist */
	if (inp == NULL)
	{
		printf("Input file no exist.\n");
		system("PAUSE");
		exit(1);
	}
    
	i = 0;	
	
	while(i < 100)
    {
		fscanf(inp, " %d", &num[i]);
		num_sort[i] = num[i];
		i++;
	}	
	
	printf("original array:\n");
	
	i = 0;	
	
	while(i < 100)
    {
		printf("%d\n", num[i]);
		i++;
	} 
	
	select_sort(num_sort, 100);
	
	printf("\n\nsorted array:\n");
	
	i = 0;
	
	while(i < 100)
    {
		printf("%d\n", num_sort[i]);
		i++;
	}
	
	if (!(outp = fopen("Numbers_sorted.txt", "w")))
	{
		printf("Error!\n");
		return 0;
	}
	
	i = 0;

	while (i < 100)
	{
		fprintf(outp, "%d\n", num_sort[i]);
		i++;
	}
	
	
	
	/* close file */
	fclose(inp);
	fclose(outp);
	
	system("PAUSE");
	return 0;
}

/* Sort the array */
void select_sort(int array[], int n)
{
    if(n > 1)
    {
        int temp, j, max_index;
    
		max_index = n - 1;
		for(j = n - 2; j >= 0; --j)
			if(array[j] > array[max_index])
				max_index = j;
            
		if(max_index != n - 1)
		{
			temp = array[n - 1];
			array[n - 1] = array[max_index];
			array[max_index] = temp;
		}
		
        select_sort(array, n - 1);
    }
}
