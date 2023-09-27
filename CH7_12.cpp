#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void search(int binary[], int *top,int *bottom,int *middle,int *n,bool *found);           /*void a function to search the number*/

int main()
{
	int binary[10] = { 654,51,98,64,84,384,1,684,35,125 };                                /*make an array at first*/
	int bottom = 0, top = 9, middle,n;                                                    /*the bottom,top and middle of the array, 'n'refers to the number that the user wants to find*/
	bool found = false;
	int change;                                                                           /*it is used to sort the array*/

	printf("\nEnter the number you want to search =>");                                   /*prompt the user to enter the number he or she wants to find*/
	scanf("%d", &n);
	printf("\n\nThe array in the beginning was=>");                                       /*print out what the array looks like in the beginning*/
	for (int i = 0; i < 10; i++)                                                          /*run the loop 10 times to print 10 numbers*/
	{
		printf("%d ", binary[i]);
	}
	for (int i = 0; i < 9; i++)                                                           /*to sort the array from the smallest the the largest*/
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (binary[i] > binary[j])
			{
				change = binary[i];
				binary[i] = binary[j];
				binary[j] =change;
			}
		}
	}
	printf("\nThe array after sorted is     =>");                                         /*print out what the array looks like after sorted*/
	for (int i = 0; i < 10; i++)                                                          /*run the loop 10 times to print 10 numbers*/
	{
		printf("%d ", binary[i]);
	}

	while (top != bottom&&found==false)                                                   /*if found the number or top equals to bottom, stop the loop*/
	{  
		search(binary,&top, &bottom, &middle, &n, &found);                                /*the loop will repeated call the function to find the number while the loop continue running*/
	}
	if (found==true)                                                                      /*if found the number, the place is equal to the middle, but the order is 0 ~ 9, so it needs to plus 1*/
	{
		printf("\n\nThe number %d is at the %d place of the array.", n, middle +1);
	}
	else if (binary[top] == n)                                                            /*if top = bottom = the number that user is finding, the place is equal to the top and bottom, but the order is 0 ~ 9, so it needs to plus 1*/
	{
		printf("\n\nThe number %d is at the %d place of the array.", n, top + 1);
	}
	else                                                                                  /*if top = bottom but doesn't equals to the number, the number isn't in the array*/
	{
		printf("\n\nThe number %d isn't in the array.",n);
	}

	system("PAUSE");
	return(0);
}

void search(int binary[],int* top, int* bottom, int* middle, int* n, bool* found)
{
	*middle = (*bottom + *top) / 2;                                                       /*calculate the middle's digit*/

	if (binary[*middle] == *n)                                                            /*if middle = the number, it means that we find the number*/
	{
		*found = true;
	}
	else if (binary[*middle] > *n)                                                        /*if middle doesn't equals to the number, and middle is larger than the number, make top=middle-1 to make middle closer to the number while calculating next time*/
	{
		*top = *middle - 1;
	}
	else if (binary[*middle] < *n)                                                        /*if middle doesn't equals to the number, and middle is smaller than the number, make bottom=middle+1 to make middle closer to the number while calculating next time*/
	{
		*bottom = *middle + 1;
	}
}
